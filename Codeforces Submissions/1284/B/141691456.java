import java.util.*;


public class C {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int k = n;
        long res =0;

        ArrayList<Integer> max = new ArrayList<>();
        ArrayList<Integer> min = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int l =s.nextInt();
            boolean t = false;
            int el[] = new int[l] ;
            el[0]=s.nextInt();
            for (int j = 1; j < l; j++) {
                el[j] = s.nextInt();
                if(el[j]>el[j-1])t = true;

            }
            if(t){
               res+=2*k -1;
               k--;

            }
            else{

                max.add(el[0]);
                min.add(el[l-1]);
            }

        }

        Collections.sort(min);
        Collections.sort(max);
        int i=0,j=0;
        int tot=0;
        while(j<max.size() && i < min.size()){
            if(min.get(i)<max.get(j)){
          i++;
          tot++;

            }
            else {
res+=tot;
            j++;
            }

        }
        if(j< max.size())res+=(long)tot*(max.size()-j);
       System.out.println(res);
    }
}
