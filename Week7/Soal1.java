import java.util.*;

public class Soal1 {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        Scanner inp = new Scanner(System.in);

        int n = inp.nextInt();

        double nilai = inp.nextDouble();
        double[] arr = new double[n];

        arr[0] = nilai;

        double total = nilai;
        
        double min = nilai;
        double max = nilai;

        for(int i = 1; i < n; i++){
          nilai = inp.nextDouble();
          arr[i] = nilai;
          total += nilai;

          if (nilai < min) min = nilai;
          if (nilai > max) max = nilai;
        }

        double mean = total/n;

        double sigma = 0;

        for(int i = 0; i < n; i++){
          sigma += Math.pow(arr[i] - mean, 2);
        }

        double std = Math.sqrt(sigma/(n-1));

        System.out.printf("%.2f %.2f\n", min, max);
        System.out.printf("%.2f %.2f\n", mean, std);

    }
}