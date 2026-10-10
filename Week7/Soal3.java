import java.util.*;

interface Number {
    double absoluteValue();
}

class Rational implements Number {
    private int pembilang;
    private int penyebut;
    public Rational(int a, int b){
        this.pembilang = a;
        this.penyebut = b;
    }

    @Override
    public double absoluteValue()  { 
        double pecahan = (double) pembilang / penyebut;
        if (pecahan < 0) pecahan = pecahan * -1;
        return pecahan;
    }

}

class Real implements Number {
    private double value;
    public Real(double a){
        this.value = a;
    }
    
    @Override
    public double absoluteValue() {
        if (value < 0) value = value * -1;
        return value;
    }
}

class Complex implements Number {
    private double real;
    private double imaginary;
    public Complex(double a, double b){
        this.real = a;
        this.imaginary = b;
    }

    @Override
    public double absoluteValue() {
        return Math.sqrt(real * real + imaginary * imaginary);
    }
}

public class Soal3 {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        Scanner inp = new Scanner(System.in);

        int n = inp.nextInt();

        char jenis;
        double bilangan1;
        double bilangan2;

        double total = 0;

        for (int i = 0; i < n; i++){
            jenis = inp.next().charAt(0);
            bilangan1 = inp.nextDouble();

            if(jenis == 'R'){
                Real r = new Real(bilangan1);
                total += r.absoluteValue();
            }

            if(jenis == 'P'){
                bilangan2 = inp.nextDouble();
                Rational p = new Rational((int) bilangan1, (int) bilangan2);
                total += p.absoluteValue();
            }

            if(jenis == 'C'){
                bilangan2 = inp.nextDouble();
                Complex c = new Complex(bilangan1, bilangan2);
                total += c.absoluteValue();
            }
        }

        System.out.printf("%.2f\n", total);
    }
}