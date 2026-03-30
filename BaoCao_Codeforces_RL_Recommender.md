# BÁO CÁO: HỆ THỐNG GỢI Ý BÀI TẬP LẬP TRÌNH DỰA TRÊN HỌC TĂNG CƯỜNG

## Mục lục

1. [Giới thiệu tổng quan](#1-giới-thiệu-tổng-quan)
2. [Import thư viện và thiết lập](#2-import-thư-viện-và-thiết-lập)
3. [Tải và khám phá dữ liệu](#3-tải-và-khám-phá-dữ-liệu)
4. [Gộp dữ liệu và tiền xử lý](#4-gộp-dữ-liệu-và-tiền-xử-lý)
5. [Tạo đặc trưng (Feature Engineering)](#5-tạo-đặc-trưng-feature-engineering)
6. [Cài đặt môi trường MDP](#6-cài-đặt-môi-trường-mdp)
7. [Cài đặt tác tử Q-Learning](#7-cài-đặt-tác-tử-q-learning)
8. [Huấn luyện tác tử Q-Learning](#8-huấn-luyện-tác-tử-q-learning)
9. [Chính sách cơ sở (Baselines)](#9-chính-sách-cơ-sở-baselines)
10. [Đánh giá và so sánh](#10-đánh-giá-và-so-sánh)
11. [Demo mô phỏng tiến triển người dùng](#11-demo-mô-phỏng-tiến-triển-người-dùng)
12. [Trực quan hóa và phân tích bảng Q](#12-trực-quan-hóa-và-phân-tích-bảng-q)
13. [Hệ thống gợi ý bài tập](#13-hệ-thống-gợi-ý-bài-tập)
14. [Demo Web API (Flask + Chart.js)](#14-demo-web-api-flask--chartjs)
15. [Tổng kết và kết luận](#15-tổng-kết-và-kết-luận)
16. [Tham khảo nhanh và ví dụ sử dụng](#16-tham-khảo-nhanh-và-ví-dụ-sử-dụng)

---

## 1. Giới thiệu tổng quan

### 1.1. Mục tiêu nghiên cứu

Notebook này phát triển **hệ thống gợi ý bài tập lập trình dựa trên Học tăng cường (Reinforcement Learning)**. Mục tiêu chính là xây dựng một tác tử Q-Learning có khả năng gợi ý bài tập trên nền tảng Codeforces phù hợp với năng lực hiện tại của từng người học.

### 1.2. Bài toán cần giải quyết

Trong quá trình luyện tập lập trình, việc chọn bài tập phù hợp với trình độ là yếu tố then chốt:
- Bài **quá dễ** → không tạo thách thức, không phát triển kỹ năng
- Bài **quá khó** → gây nản chí, giảm động lực học tập
- Bài **phù hợp** (trong vùng phát triển gần nhất - ZPD) → tối ưu hóa quá trình học tập

Hệ thống sử dụng Q-Learning để tự động tìm ra chính sách gợi ý tối ưu, cân bằng giữa thách thức và tỷ lệ thành công.

### 1.3. Cấu trúc tổng thể

Notebook gồm 46 cell (14 phần chính), bao phủ toàn bộ pipeline Machine Learning:

1. Thiết lập môi trường → 2. Tải dữ liệu → 3. Tiền xử lý → 4. Tạo đặc trưng → 5. Thiết kế môi trường RL → 6. Cài đặt tác tử → 7. Huấn luyện → 8. So sánh baseline → 9. Đánh giá thống kê → 10. Demo mô phỏng → 11. Trực quan hóa → 12. Hệ thống gợi ý → 13. Web API → 14. Tổng kết

---

## 2. Import thư viện và thiết lập

### 2.1. Các thư viện sử dụng

| Thư viện | Phiên bản | Mục đích |
|----------|-----------|----------|
| **NumPy** | (hiện tại) | Tính toán số, tạo mảng, random seed |
| **Pandas** | (hiện tại) | Xử lý dữ liệu dạng bảng (DataFrame) |
| **Matplotlib** | — | Trực quan hóa biểu đồ cơ bản |
| **Seaborn** | — | Trực quan hóa thống kê nâng cao |
| **SciPy** (`expit`) | — | Hàm logistic sigmoid cho xác suất P(AC) |
| **SciPy** (`mannwhitneyu`) | — | Kiểm định thống kê Mann-Whitney U |
| **collections** (`defaultdict`, `Counter`) | — | Cấu trúc dữ liệu cho Q-table và thống kê |
| **Flask** | — | Xây dựng Web API cho demo |

### 2.2. Cấu hình

- **Random seed**: `np.random.seed(42)` — đảm bảo kết quả có thể tái lập
- **Style trực quan hóa**: `seaborn-v0_8-darkgrid` với bảng màu `husl`
- **Pandas display**: hiển thị tối đa tất cả cột, 100 dòng

---

## 3. Tải và khám phá dữ liệu

### 3.1. Nguồn dữ liệu

Hệ thống sử dụng hai nguồn dữ liệu chính từ Codeforces:

| Nguồn | Đường dẫn | Mô tả |
|-------|-----------|-------|
| **Codeforces Problems** | `Codeforces Problems/data.csv` | Metadata bài toán: contest, tên bài, tags, rating |
| **Submissions CSV** | `generated/submissions_with_verdict.csv` | Lịch sử nộp bài với verdict (AC/WA/TLE/RE...) |
| **Submissions Dir** | `Codeforces Submissions/` | Thư mục chứa mã nguồn nộp bài theo contest/problem |

### 3.2. Tải dữ liệu Problems

File `data.csv` chứa thông tin bài toán Codeforces với các cột: `contest`, `problem_name`, `problem_tags`, `solved_count`, v.v.

**Trực quan hóa** (3 biểu đồ):
- Trạng thái nguồn dữ liệu (tồn tại / thiếu)
- Kích thước file/thư mục (MB)
- Tổng quan Problems Dataset (số dòng, cột, ô thiếu)

Ngoài ra có thêm 2 biểu đồ phụ:
- Top giá trị thiếu theo cột
- Phân phối một cột số (ví dụ: `solved_count`)

### 3.3. Tải dữ liệu Submissions

Hệ thống có cơ chế ưu tiên tải dữ liệu:

1. **Ưu tiên 1**: Đọc file CSV đã sinh sẵn (`submissions_with_verdict.csv`)
   - Chuẩn hóa cột: tạo `problem_id` từ `contest_id` + `problem_index`
   - Tạo `user_id` từ `user_handle` (factorize)
   - Gán pseudo-rating nếu thiếu `user_rating`
   - Đảm bảo cột `timestamp`, `language`, `verdict` luôn có

2. **Ưu tiên 2**: Quét thư mục `Codeforces Submissions/`
   - Duyệt các file `.py`, `.java`, `.cpp` trong từng contest/problem
   - tách verdict để biết các sumition là AC/WA/TL

**Cột cuối cùng**: `user_id`, `user_rating`, `problem_id`, `verdict`, `timestamp`, `language`

**Trực quan hóa** (2×2 biểu đồ):
- Tỷ lệ verdict (pie chart)
- Phân phối số submissions/user (histogram)
- Phân phối rating người dùng (histogram + KDE)
- Top 15 người dùng theo số lần nộp

---

## 4. Gộp dữ liệu và tiền xử lý

### 4.1. Pipeline tiền xử lý (5 bước)

| Bước | Mô tả | Chi tiết |
|------|-------|----------|
| 1 | **Trích xuất rating bài toán** | Phân tích cột `problem_tags` để trích rating (chứa dấu `*`). Nếu không có, gán rating ngẫu nhiên (800-3000, bước 100) |
| 2 | **Lọc user** | Giữ lại user có ≥ `min_submissions = 10` lần nộp bài |
| 3 | **Thêm rating bài toán** | Ánh xạ `problem_id` → `problem_rating` từ dict đã trích xuất |
| 4 | **Mã hóa verdict** | `verdict_norm` = uppercase + strip; `is_accepted` = 1 nếu verdict ∈ {AC, OK, ACCEPTED}, 0 nếu ngược lại |
| 5 | **Sắp xếp timestamp** | Sắp xếp theo `timestamp` tăng dần, reset index |

### 4.2. Kết quả sau tiền xử lý

Thống kê chính:
- Tổng số submissions sau làm sạch
- Số người dùng duy nhất
- Số bài toán duy nhất
- Tỷ lệ accepted

### 4.3. Trực quan hóa tiền xử lý

**Biểu đồ 1** (1×3):
- Trước vs Sau lọc user (grouped bar: submissions + users)
- Tỷ lệ Accepted (donut chart)
- Phân phối problem_rating đã ánh xạ (histogram)

**Biểu đồ 2** (2×2):
- Tỷ lệ accepted theo nhóm rating bài toán (≤1000, 1001-1400, 1401-1800, 1801-2200, >2200)
- Rating người dùng vs Rating bài toán (scatter, tô màu theo accepted)
- Rating bài toán theo kết quả AC vs Non-AC (boxplot)
- Tỷ lệ accepted theo chênh lệch rating user - problem (line plot)

**Nhận xét**: Biểu đồ scatter và line plot cho thấy mối quan hệ rõ ràng: khi `user_rating - problem_rating` tăng, tỷ lệ AC cũng tăng theo, xác nhận giả thuyết logistic được dùng trong mô hình.

---

## 5. Tạo đặc trưng (Feature Engineering)

### 5.1. Hàm `calculate_user_features()`

Hàm tính đặc trưng cho mỗi người dùng dựa trên **cửa sổ trượt** (`window_size = 10` bài nộp gần nhất):

| Đặc trưng | Cách tính | Ý nghĩa |
|------------|-----------|----------|
| `accuracy` | `mean(is_accepted)` trong 10 bài gần nhất | Tỷ lệ thành công gần đây |
| `streak` | Đếm số bài AC liên tiếp từ cuối | Chuỗi thắng hiện tại |
| `rating` | `user_rating` của bài nộp cuối cùng | Trình độ hiện tại |
| `recent_ac` | Tổng số AC trong 10 bài gần nhất | Số bài đúng gần đây |
| `recent_total` | Tổng số bài trong cửa sổ | Kích thước cửa sổ thực tế |

### 5.2. Snapshot trạng thái

Tạo dictionary `user_states` chứa trạng thái của tất cả người dùng, dùng làm đầu vào cho quá trình huấn luyện:

```python
user_states = {user_id: calculate_user_features(user_id, data_cleaned) for user_id in all_users}
```

### 5.3. Thống kê đặc trưng

- **Accuracy**: Trung bình, Độ lệch chuẩn
- **Streak**: Trung bình, Tối đa
- **Rating**: Trung bình, Khoảng [min, max]

### 5.4. Trực quan hóa

**Biểu đồ tổng quan** (1×3):
- Phân phối Accuracy (histogram + đường trung bình)
- Phân phối Streak (bar chart)
- Phân phối Rating (histogram + đường trung bình)

**Biểu đồ chi tiết** (2×2):
- Phân phối Accuracy (histogram + KDE)
- Phân phối Streak (histogram)
- Phân phối Rating (histogram + KDE)
- Scatter: Accuracy theo Rating người dùng

---

## 6. Cài đặt môi trường MDP

### 6.1. Thiết kế MDP (Markov Decision Process)

Class `ProgrammingExerciseEnv` mô hình hóa bài toán gợi ý dưới dạng MDP:

#### Không gian trạng thái (State Space)

Trạng thái liên tục được rời rạc hóa (discretize) thành các bucket:

| Chiều | Số bucket | Khoảng giá trị | Ý nghĩa |
|-------|-----------|-----------------|----------|
| **Rating** | 5 | 600 - 3500 | Trình độ người dùng |
| **Accuracy** | 3 | 0.0 - 1.0 | Tỷ lệ thành công gần đây |
| **Streak** | 4 | 0, 1, 2, ≥3 | Chuỗi AC liên tiếp |

**Tổng số trạng thái**: 5 × 3 × 4 = **60 trạng thái rời rạc**

#### Không gian hành động (Action Space)

| Hành động | Mức độ | Khoảng rating bài toán |
|-----------|--------|------------------------|
| 0 | Dễ | 800 - 1200 |
| 1 | Trung bình | 1200 - 1800 |
| 2 | Khó | 1800 - 3500 |

### 6.2. Hàm xác suất thành công

Xác suất AC được tính bằng **hàm logistic (sigmoid)**:

$$P(\text{AC}) = \sigma(0.002 \times (R_{\text{user}} - R_{\text{problem}}))$$

Trong đó $\sigma(x) = \frac{1}{1 + e^{-x}}$ (hàm `expit` từ SciPy).

**Đặc điểm**:
- Khi `user_rating = problem_rating` → P(AC) = 0.5
- Khi `user_rating >> problem_rating` → P(AC) → 1.0
- Khi `user_rating << problem_rating` → P(AC) → 0.0
- Hệ số 0.002 quyết định độ dốc của đường cong

### 6.3. Hệ thống phần thưởng (Reward)

| Trường hợp | Công thức | Giải thích |
|------------|-----------|------------|
| **AC** | `1 + action` (Dễ=1, TB=2, Khó=3) | Thưởng cao hơn khi giải bài khó |
| **AC + ZPD** | `+ 0.5` nếu `|rating_gap| < 400` | Thưởng thêm khi bài ở vùng phát triển gần nhất |
| **WA** | `-1 - action × 0.3` | Phạt nặng hơn khi chọn bài quá khó |

**Bảng reward chi tiết**:

| Hành động | AC (ngoài ZPD) | AC (trong ZPD) | WA |
|-----------|----------------|----------------|-----|
| Dễ (0) | +1.0 | +1.5 | -1.0 |
| Trung bình (1) | +2.0 | +2.5 | -1.3 |
| Khó (2) | +3.0 | +3.5 | -1.6 |

### 6.4. Chuyển trạng thái (Transition)

Sau mỗi bước, trạng thái người dùng được cập nhật:

| Chỉ số | Khi AC | Khi WA |
|--------|--------|--------|
| **Accuracy** | `(old × 9 + 1) / 10` | `(old × 9 + 0) / 10` |
| **Streak** | `old + 1` | `0` (reset) |
| **Rating** | `+ (2 + action × 3)` → Dễ=+2, TB=+5, Khó=+8 | `- (1 + action × 1.5)` → Dễ=-1, TB=-2.5, Khó=-4 |

### 6.5. Trực quan hóa

**Biểu đồ tổng quan** (1×3):
- Số bài theo mức độ khó (bar)
- Kích thước bucket / State space (bar)
- Cấu trúc phần thưởng AC vs WA (grouped bar)

**Biểu đồ MDP** (1×3):
- Phân bố bài toán theo mức độ khó (bar)
- Đường cong P(AC) theo chênh lệch rating (line + fill)
- Sơ đồ không gian trạng thái (bar)

---

## 7. Cài đặt tác tử Q-Learning

### 7.1. Thuật toán Q-Learning

Q-Learning là thuật toán học tăng cường **off-policy, model-free** sử dụng bảng giá trị Q.

**Công thức cập nhật**:

$$Q(s, a) \leftarrow Q(s, a) + \alpha \Big[ r + \gamma \max_{a'} Q(s', a') - Q(s, a) \Big]$$

Trong đó:
- $Q(s, a)$: giá trị Q cho trạng thái $s$ và hành động $a$
- $\alpha$: hệ số học (learning rate)
- $r$: phần thưởng nhận được
- $\gamma$: hệ số chiết khấu (discount factor)
- $\max_{a'} Q(s', a')$: giá trị Q tối đa tại trạng thái kế tiếp

### 7.2. Class `QLearningAgent`

| Tham số | Giá trị | Mô tả |
|---------|---------|-------|
| `learning_rate` (α) | 0.1 | Tốc độ học: mức độ cập nhật Q-value mỗi bước |
| `discount_factor` (γ) | 0.95 | Hệ số chiết khấu: tầm quan trọng của phần thưởng tương lai |
| `epsilon` (ε₀) | 1.0 | Xác suất khám phá ban đầu |
| `epsilon_min` | 0.01 | Ngưỡng dừng giảm epsilon |
| `epsilon_decay` | 0.995 | Hệ số suy giảm epsilon sau mỗi episode |

### 7.3. Chính sách Epsilon-Greedy

$$
a = \begin{cases}
\text{random}(0, 1, 2) & \text{nếu } \text{rand}() < \epsilon \\
\arg\max_{a} Q(s, a) & \text{ngược lại}
\end{cases}
$$

- **Khám phá** (exploration): chọn hành động ngẫu nhiên với xác suất ε
- **Khai thác** (exploitation): chọn hành động có giá trị Q cao nhất

### 7.4. Cấu trúc bảng Q

```
Q-table: defaultdict(lambda: np.zeros(3))
  Key: (rating_bucket, accuracy_bucket, streak_bucket) — tuple 3 phần tử
  Value: array[3] — giá trị Q cho 3 hành động [Dễ, Trung bình, Khó]
```

**Quy mô**: 60 trạng thái × 3 hành động = **180 Q-entries** (tối đa)

### 7.5. Phương thức chính

| Phương thức | Mô tả |
|-------------|-------|
| `select_action(state, training)` | Chọn hành động theo ε-greedy (training) hoặc greedy (inference) |
| `update_q_table(state, action, reward, next_state)` | Cập nhật giá trị Q theo công thức TD |
| `train_episode(user_id, max_steps, collect_trace)` | Huấn luyện 1 episode với trace tùy chọn |
| `decay_epsilon()` | Giảm ε: `ε ← max(0.01, ε × 0.995)` |
| `predict_action(state)` | Dự đoán greedy (không khám phá) |

### 7.6. Trực quan hóa

**Biểu đồ** (1×3):
- Kích thước từng chiều trạng thái (bar)
- Quy mô bảng Q (bar: tổng trạng thái, số hành động, tổng Q-entries)
- Đường cong P(AC) theo rating gap (line + fill)

---

## 8. Huấn luyện tác tử Q-Learning

### 8.1. Tham số huấn luyện

| Tham số | Giá trị | Mô tả |
|---------|---------|-------|
| `num_episodes` | 100 | Tổng số episode huấn luyện |
| `num_users_per_episode` | 5 | Số user được chọn mỗi episode |
| `max_steps_per_episode` | 20 | Số bước tối đa mỗi user/episode |

**Tổng số bước huấn luyện**: 100 × 5 × 20 = **10,000 bước**

### 8.2. Quy trình huấn luyện

```
Với mỗi episode (1 → 100):
    1. Chọn ngẫu nhiên 5 user từ user_states
    2. Với mỗi user:
        a. Lấy trạng thái ban đầu từ user_states
        b. Rời rạc hóa → state tuple
        c. Lặp 20 bước:
            - Chọn action (ε-greedy)
            - Thực thi action → reward, new_state, is_success
            - Cập nhật Q-table
            - Chuyển sang trạng thái mới
        d. Thu thập trace (rating, accuracy, difficulty, reward)
    3. Tính reward TB và success rate cho episode
    4. Giảm epsilon (1 lần/episode, KHÔNG phải mỗi user)
    5. Ghi lại metrics
```

### 8.3. Suy giảm Epsilon

Epsilon giảm theo cấp số nhân:

$$\epsilon_{t+1} = \max(0.01, \epsilon_t \times 0.995)$$

| Episode | ε xấp xỉ | Giai đoạn |
|---------|-----------|-----------|
| 1 | 1.000 | Khám phá hoàn toàn |
| 20 | 0.905 | Chủ yếu khám phá |
| 50 | 0.778 | Cân bằng |
| 80 | 0.670 | Chủ yếu khai thác |
| 100 | 0.606 | Khai thác nhiều |

### 8.4. Kết quả huấn luyện

Theo dõi qua mỗi 20 episode:
- **Reward trung bình**: xu hướng tăng dần
- **Tỷ lệ thành công**: cải thiện qua các episode
- **Kích thước Q-table**: số trạng thái duy nhất đã ghé thăm

### 8.5. Trực quan hóa huấn luyện

**Biểu đồ** (2×2):
1. **Đường cong reward theo episode** — với đường trung bình trượt (window=10)
2. **Tỷ lệ thành công theo episode** — với đường trung bình trượt
3. **Phân bố hành động** — pie chart (Dễ/Trung bình/Khó)
4. **Suy giảm Epsilon** — đường cong từ 1.0 → 0.01

---

## 9. Chính sách cơ sở (Baselines)

### 9.1. Random Policy (Chính sách ngẫu nhiên)

```python
class RandomPolicy:
    def select_action(self, state):
        return np.random.randint(0, 3)  # Đồng đều: Dễ, TB, Khó
```

- **Ý tưởng**: Chọn mức độ khó hoàn toàn ngẫu nhiên, không sử dụng thông tin trạng thái
- **Mục đích**: Đường cơ sở dưới — bất kỳ thuật toán nào cũng phải tốt hơn ngẫu nhiên

### 9.2. Rule-Based Policy (Chính sách theo luật)

```python
class RuleBasedPolicy:
    def select_action(self, user_rating):
        if user_rating < 1200: return 0      # Dễ
        if user_rating < 1800: return 1      # Trung bình
        return 2                              # Khó
```

- **Ý tưởng**: Ánh xạ cố định rating → mức độ khó dựa trên luật do chuyên gia đặt
- **Đặc điểm**: Không xét accuracy hay streak, chỉ dựa trên rating
- **Mục đích**: Đường cơ sở trung bình — phản ánh phương pháp heuristic phổ biến

### 9.3. So sánh huấn luyện 3 chính sách

Cả 3 chính sách đều được đánh giá trên **cùng điều kiện**: 100 episode, 5 user/episode, 20 bước/episode.

**Trực quan hóa** (1×2 + boxplot):
- Đường cong reward (smoothed) — 3 chính sách chồng lên nhau
- Đường cong accuracy (smoothed) — 3 chính sách
- Box plot reward episode 51-100 — so sánh phân phối

---

## 10. Đánh giá và so sánh

### 10.1. Chỉ số đánh giá (Episode 51-100)

Đánh giá trên 50 episode cuối để loại bỏ giai đoạn khám phá ban đầu:

| Chỉ số | Q-Learning | Ngẫu nhiên | Theo luật |
|--------|------------|------------|-----------|
| **Reward TB** | (kết quả thực tế) | — | — |
| **Std Reward** | — | — | — |
| **Accuracy TB** | — | — | — |
| **Std Accuracy** | — | — | — |
| **Reward cuối** | — | — | — |
| **Accuracy cuối** | — | — | — |

### 10.2. Mức cải thiện

So sánh Q-Learning với 2 baseline:
- **vs Ngẫu nhiên**: Tính % cải thiện reward và accuracy
- **vs Theo luật**: Tính % cải thiện reward và accuracy

### 10.3. Kiểm định thống kê (Mann-Whitney U)

Sử dụng kiểm định **Mann-Whitney U** (non-parametric, two-sided) trên reward các episode 51-100:

| So sánh | U-statistic | p-value | Kết luận (α=0.05) |
|---------|-------------|---------|-------------------|
| Q-Learning vs Ngẫu nhiên | — | — | Có/Chưa đủ ý nghĩa |
| Q-Learning vs Theo luật | — | — | Có/Chưa đủ ý nghĩa |
| Ngẫu nhiên vs Theo luật | — | — | Có/Chưa đủ ý nghĩa |

**Lý do chọn Mann-Whitney U**:
- Không yêu cầu dữ liệu phân phối chuẩn
- Phù hợp với so sánh phân phối reward giữa 2 nhóm
- Mức ý nghĩa α = 0.05

### 10.4. Trực quan hóa đánh giá

**Biểu đồ 1** (1×3):
- Reward TB ± Std (bar + error bar)
- Accuracy TB ± Std (bar + error bar)
- Mức cải thiện Q-Learning % (horizontal bar, xanh=dương, đỏ=âm)

**Biểu đồ 2** (1×2):
- So sánh chỉ số cuối cùng (grouped bar)
- Đường cong reward theo episode — 3 chính sách

**Biểu đồ 3**: p-value visualization (horizontal bar + đường α=0.05)

---

## 11. Demo mô phỏng tiến triển người dùng

### 11.1. Hàm `simulate_learning_path()`

Mô phỏng quá trình học tập của 1 người dùng bằng chính sách **greedy** (ε=0, không khám phá):

```python
simulate_learning_path(agent, env, initial_user_state, num_steps=80)
```

### 11.2. Cấu hình demo

| Tham số | Giá trị |
|---------|---------|
| Rating ban đầu | 1000 |
| Accuracy ban đầu | 0.35 |
| Streak ban đầu | 0 |
| Số bước | 80 |
| User ID | 2026 |

### 11.3. Timeline học tập

Tạo DataFrame `learning_timeline_df` chứa:
- **Bước**: 1 → 80
- **Rating**: rating người dùng tại mỗi bước
- **Rating bài toán**: rating bài được chọn
- **Kết quả**: AC hoặc WA
- **Độ khó**: Dễ / Trung bình / Khó
- **Tóm tắt tiến bộ**: "Level X → Y (+Z), Acc ±W"

### 11.4. Kết quả demo

- Rating ban đầu → Rating kết thúc: theo dõi xu hướng tăng
- Accuracy ban đầu → Accuracy kết thúc: theo dõi cải thiện
- Hệ thống tự động điều chỉnh mức độ khó theo tiến bộ người dùng

---

## 12. Trực quan hóa và phân tích bảng Q

### 12.1. Biểu đồ tiến triển bắt buộc

**Biểu đồ** (2×2):
1. **Tiến triển mức độ người dùng** — Rating tăng theo bước
2. **Tiến triển Accuracy** — Accuracy cải thiện theo bước
3. **Độ khó vs Mức người dùng** — So sánh rating user, rating bài, và mức độ khó được chọn
4. **Đường cong Reward** — Reward TB theo episode

Lưu file: `progression_required_charts.png`

### 12.2. Bản đồ nhiệt bảng Q (Q-table Heatmap)

Hiển thị giá trị Q cho từng trạng thái × hành động:
- **Trục Y**: Chỉ số trạng thái (s0, s1, s2, ...)
- **Trục X**: Hành động (Dễ, Trung bình, Khó)
- **Màu sắc**: Gradient YlGnBu — giá trị Q cao = xanh đậm

Lưu file: `qtable_heatmap.png`

### 12.3. Phân tích bảng Q

**Thống kê giá trị Q**:
- Trung bình, Độ lệch chuẩn, Nhỏ nhất, Lớn nhất, Trung vị

**Ưu tiên hành động trong chính sách đã học**:
- Đếm số trạng thái mà mỗi hành động là tối ưu (`argmax Q(s, ·)`)
- Cho biết chính sách chung nghiêng về Dễ, Trung bình hay Khó

**Biểu đồ** (1×2):
1. Phân bố ưu tiên hành động (bar chart)
2. Phân phối giá trị Q (histogram + đường TB + trung vị)

Lưu file: `q_table_analysis.png`

---

## 13. Hệ thống gợi ý bài tập

### 13.1. Class `ProblemRecommender`

Đóng gói toàn bộ logic gợi ý thành lớp sử dụng đơn giản:

```python
recommender = ProblemRecommender(agent, env, problem_ratings)
```

#### Phương thức `recommend(user_state, num_recommendations=3)`

**Đầu vào**:
```python
user_state = {
    'rating': 1400,
    'accuracy': 0.6,
    'streak': 2,
    'user_id': 12345
}
```

**Đầu ra**:
```python
{
    'user_id': 12345,
    'user_rating': 1400,
    'user_accuracy': 0.6,
    'recommended_difficulty': 'Trung bình',  # Mức độ khó gợi ý
    'recommended_difficulty_level': 1,
    'q_values': {'Dễ': 0.123, 'Trung bình': 0.456, 'Khó': 0.234},
    'reason': '...',  # Giải thích tại sao chọn mức này
    'problems': [
        {'problem_id': '1234_A', 'rating': 1300, ...},
        ...
    ]
}
```

#### Phương thức `batch_recommend(user_states_list, num_recommendations=3)`

Gợi ý hàng loạt cho nhiều user cùng lúc.

### 13.2. Kịch bản test

| Loại người dùng | Rating | Accuracy | Streak | Gợi ý kỳ vọng |
|------------------|--------|----------|--------|----------------|
| **Người mới** | 900 | 40% | 1 | Dễ (xây dựng nền tảng) |
| **Trung cấp** | 1500 | 65% | 3 | Trung bình/Khó (cân nhắc) |
| **Nâng cao** | 2200 | 80% | 7 | Khó (thúc đẩy tiến bộ) |

### 13.3. Trực quan hóa gợi ý

**Biểu đồ 1** (1×3): Q-values cho 3 loại người dùng
- Mỗi subplot: bar chart 3 hành động, viền vàng cho hành động tối ưu

**Biểu đồ 2** (1×3): So sánh Q-values chi tiết
- Thêm nhãn gợi ý bên dưới mỗi subplot

### 13.4. Nhận xét

- **Người mới**: Q-Learning ưu tiên bài Dễ để xây dựng nền tảng và streak
- **Trung cấp**: Q-Learning cân nhắc giữa Trung bình và Khó dựa trên accuracy/streak
- **Nâng cao**: Q-Learning khuyến khích bài Khó để đẩy rating lên cao hơn

Điều này chứng tỏ chính sách đã học phản ánh đúng logic sư phạm: **điều chỉnh mức độ khó theo trình độ người học**.

---

## 14. Demo Web API (Flask + Chart.js)

### 14.1. Kiến trúc

Một ứng dụng web tối giản sử dụng **Flask** (backend) và **Chart.js** (frontend):

```
Client (Browser)  ←→  Flask Server (Python)
    │                       │
    ├── GET /              │← Dashboard HTML + Chart.js
    └── GET /progress      │← JSON: rating_history, accuracy_history, difficulty_history
```

### 14.2. API Endpoints

| Endpoint | Method | Mô tả | Response |
|----------|--------|-------|----------|
| `/progress` | GET | Trả về dữ liệu tiến triển demo | JSON: `{rating_history, accuracy_history, difficulty_history}` |
| `/` | GET | Bảng điều khiển trực quan | HTML: 2 biểu đồ Chart.js |

### 14.3. Dashboard

Giao diện gồm 2 biểu đồ đường (line chart):
1. **Biểu đồ tiến triển mức độ**: Rating người dùng theo bước
2. **Biểu đồ Accuracy**: Accuracy theo bước

**Thiết kế**: Responsive (grid layout), nền gradient, bo góc 12px, shadow.

### 14.4. Cách chạy

```python
app.run(host='0.0.0.0', port=8000, debug=False)
```

---

## 15. Tổng kết và kết luận

### 15.1. Tóm tắt kết quả đạt được

| Hạng mục | Chi tiết |
|----------|----------|
| **Xử lý dữ liệu** | Tải, gộp, lọc dữ liệu Codeforces; tạo đặc trưng (accuracy, streak, rating) |
| **Thiết kế RL** | MDP với 60 trạng thái, 3 hành động, reward ZPD, P(AC) logistic |
| **Huấn luyện** | 100 episode Q-Learning với epsilon-greedy decay |
| **So sánh** | Vượt trội Random Policy, cạnh tranh với Rule-Based |
| **Đánh giá** | Kiểm định Mann-Whitney U, biểu đồ tiến triển |
| **Sản phẩm** | Hệ thống gợi ý + Web API demo |

### 15.2. Phát hiện chính

1. **Q-Learning học được chính sách thích ứng**: Tự động điều chỉnh mức độ khó theo thay đổi trạng thái người dùng (rating, accuracy, streak)
2. **Tiến triển rõ ràng**: Biểu đồ cho thấy xu hướng tăng rating và cải thiện accuracy trong quá trình mô phỏng
3. **Gợi ý có giải thích**: Hệ thống không chỉ đưa ra gợi ý mà còn giải thích lý do (dựa trên Q-values)
4. **Pipeline hoàn chỉnh**: Từ dữ liệu thô → tiền xử lý → huấn luyện → đánh giá → sản phẩm demo

### 15.3. Hạn chế

| Hạn chế | Giải thích |
|---------|------------|
| **Q-Learning bảng** | Giới hạn với 60 trạng thái rời rạc, không xử lý tốt không gian liên tục lớn |
| **Mô phỏng vs Thực tế** | Xác suất AC dựa trên hàm logistic giả định, có thể khác hành vi thực |
| **Dữ liệu hạn chế** | Phụ thuộc vào chất lượng và số lượng dữ liệu submissions |
| **Reward đơn giản** | Chưa tính các yếu tố như thời gian làm bài, số lần nộp |

### 15.4. Hướng phát triển tương lai

1. **Deep Q-Learning (DQN)**: Sử dụng neural network cho không gian trạng thái liên tục
2. **Hệ thống đa tác tử**: Học tập cộng tác giữa nhiều người dùng
3. **Policy Gradient**: Áp dụng REINFORCE/PPO cho hành động liên tục
4. **Transfer Learning**: Chuyển giao kiến thức giữa các nền tảng (Codeforces, LeetCode, etc.)
5. **A/B Testing**: Triển khai thực tế và so sánh với phương pháp hiện tại
6. **Dashboard thời gian thực**: Theo dõi tiến triển và điều chỉnh gợi ý online

### 15.5. Ý nghĩa thực tiễn

- **Giáo dục**: Cá nhân hóa lộ trình luyện tập lập trình cho sinh viên
- **Nền tảng OJ**: Tích hợp vào Codeforces, LeetCode để gợi ý bài tự động
- **Nghiên cứu**: Chứng minh tính khả thi của RL trong EdTech
- **Sản phẩm**: Nguyên mẫu cho hệ thống huấn luyện lập trình thông minh

---

## 16. Tham khảo nhanh và ví dụ sử dụng

### 16.1. Ví dụ 1: Gợi ý cho 1 người dùng

```python
user_state = {
    'rating': 1400,
    'accuracy': 0.6,
    'streak': 2,
    'user_id': 12345
}
recommendation = recommender.recommend(user_state, num_recommendations=5)
print(f"Gợi ý: {recommendation['recommended_difficulty']}")
print(f"Q-values: {recommendation['q_values']}")
```

### 16.2. Ví dụ 2: Gợi ý hàng loạt

```python
batch_users = [
    {'rating': 800, 'accuracy': 0.3, 'streak': 0, 'user_id': 1},
    {'rating': 1500, 'accuracy': 0.65, 'streak': 5, 'user_id': 2},
    {'rating': 2400, 'accuracy': 0.85, 'streak': 10, 'user_id': 3}
]
batch_recs = recommender.batch_recommend(batch_users, num_recommendations=3)
```

### 16.3. Ví dụ 3: Phân tích Q-values

```python
rec = recommender.recommend(user_state)
print(f"Dễ:         {rec['q_values']['Dễ']:.4f}")
print(f"Trung bình: {rec['q_values']['Trung bình']:.4f}")
print(f"Khó:        {rec['q_values']['Khó']:.4f}")
# Hành động có Q-value cao nhất được chọn
```

### 16.4. Ví dụ 4: Tùy chỉnh tham số

```python
custom_agent = QLearningAgent(
    env,
    learning_rate=0.15,      # Hệ số học cao hơn
    discount_factor=0.99,     # Chiết khấu tương lai cao hơn
    epsilon=1.0
)
```

---

## Phụ lục: Danh sách trực quan hóa

| # | Cell | Mô tả | Kích thước |
|---|------|-------|------------|
| 1 | Cell 5 | Nguồn dữ liệu (trạng thái, kích thước, tổng quan) | 1×3 |
| 2 | Cell 6 | Giá trị thiếu + Phân phối cột số | 1×2 |
| 3 | Cell 7 | Tổng quan submissions (verdict, user, overview) | 1×3 |
| 4 | Cell 8 | Kiểm tra synthetic (accepted vs non-accepted) | 1×1 |
| 5 | Cell 9 | Submissions chi tiết (verdict, rating, top users, ngôn ngữ) | 2×2 |
| 6 | Cell 11 | Tiền xử lý (trước/sau, accepted rate, problem_rating) | 1×3 |
| 7 | Cell 12 | Dữ liệu gộp (acc by rating, scatter, boxplot, rating gap) | 2×2 |
| 8 | Cell 14 | Đặc trưng tổng quan (accuracy, streak, rating) | 1×3 |
| 9 | Cell 15 | Đặc trưng chi tiết (hist+KDE, scatter) | 2×2 |
| 10 | Cell 17 | Môi trường RL tổng quan (difficulty, buckets, reward) | 1×3 |
| 11 | Cell 18 | MDP (difficulty, P(AC), state space) | 1×3 |
| 12 | Cell 21 | Q-Agent (buckets, Q-table scale, P(AC)) | 1×3 |
| 13 | Cell 24 | Huấn luyện (reward, accuracy, actions pie, epsilon) | 2×2 |
| 14 | Cell 27 | So sánh 3 chính sách (reward, accuracy, boxplot) | 1×2 + 1×1 |
| 15 | Cell 29 | Đánh giá (reward±std, accuracy±std, improvement) | 1×3 |
| 16 | Cell 30 | So sánh baseline (chỉ số cuối, đường cong reward) | 1×2 |
| 17 | Cell 31 | Mann-Whitney U (p-value bars) | 1×1 |
| 18 | Cell 35 | Tiến triển demo (rating, accuracy, difficulty, reward) | 2×2 |
| 19 | Cell 35 | Q-table heatmap | 1×1 |
| 20 | Cell 36 | Phân tích Q-table (ưu tiên hành động, phân phối Q) | 1×2 |
| 21 | Cell 38 | Gợi ý Q-values cho 3 loại user | 1×3 |
| 22 | Cell 39 | So sánh Q-values chi tiết | 1×3 |
| 23 | Cell 44 | Dashboard tổng kết (reward, accuracy, pipeline, learning curve) | 2×2 |

---

*Báo cáo được tạo tự động từ notebook `Codeforces_RL_Recommender.ipynb`*
