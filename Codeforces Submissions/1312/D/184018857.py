# в массиве будут присутствовать n - 1 разный элементов,
# ихможно выбрать столькими способами: количество сочетаний из m по n - 1
# далее выбираем элемент который будет повторяться, максимум мы взять не сможем,
# так как иначе не будет выполняться 4 условие, поэтому домножаем на n - 2
# некоторые элементы будут появляться в нашем массиве до максимума,
# а некоторые — после. Раздвоенный элемент должен появиться по обе стороны от максимума,
# но для всех остальных мы можем выбрать их сторону, поэтому ответ домножается на 2^(n - 3).
def C(num1, num2):
    result = 1
    for i in range(1, num2 + 1):
        result = result*(num1-num2+i) % 998244353
        result = result*pow(i, 998244353 - 2, 998244353)
    return result

number_first, number_second = map(int, input().strip().split(" "))
if number_first == 2:
    print(0)
else:
    dolce_gabbana = C(number_second, number_first - 1) % 998244353
    dolce_gabbana = dolce_gabbana * (number_first - 2) % 998244353
    dolce_gabbana = dolce_gabbana * 2**(number_first - 3) % 998244353
    print(dolce_gabbana % 998244353)

