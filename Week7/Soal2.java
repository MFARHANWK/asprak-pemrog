import java.util.*;

abstract class Ruang2d {
    abstract public double hitungLuas();
    abstract public double hitungKeliling();
}

class SegiEmpat extends Ruang2d{
    private double panjang;
    private double lebar;

    public SegiEmpat(double panjang, double lebar){
        this.panjang = panjang;
        this.lebar = lebar;
    }
    public double hitungLuas(){
        return panjang * lebar;
    }
    public double hitungKeliling(){
        return 2 * (panjang + lebar);
    }
}

class SegiTiga extends Ruang2d{
    private double alas;
    private double tinggi;

    public SegiTiga(double alas, double tinggi){
        this.alas = alas;
        this.tinggi = tinggi;
    }
    public double hitungLuas(){
        return alas * tinggi / 2;
    }
    public double hitungKeliling(){
        double miring = Math.sqrt(alas * alas + tinggi * tinggi);
        return alas + tinggi + miring;
    }
}


public class Soal2 {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        Scanner inp = new Scanner(System.in);

        char shape = inp.next().charAt(0);

        double sisi1;
        double sisi2;

        double totalLuasSegiEmpat = 0;
        double totalLuasSegiTiga = 0;

        double totalKelilingSegiEmpat = 0;
        double totalKelilingSegiTiga = 0;

        while (true) {
            if(shape == 'X'){
                break;
            }
            sisi1 = inp.nextDouble();
            sisi2 = inp.nextDouble();

            if(shape == 'R'){
                SegiEmpat r = new SegiEmpat(sisi1, sisi2);
                totalLuasSegiEmpat += r.hitungLuas();
                totalKelilingSegiEmpat += r.hitungKeliling();
            }
            if(shape == 'T'){
                SegiTiga s = new SegiTiga(sisi1, sisi2);
                totalLuasSegiTiga += s.hitungLuas();
                totalKelilingSegiTiga += s.hitungKeliling();
            }

            shape = inp.next().charAt(0);
        }

        System.out.println("LUAS");
        System.out.printf("- Segiempat : %.2f\n", totalLuasSegiEmpat);
        System.out.printf("- Segitiga : %.2f\n", totalLuasSegiTiga);
        System.out.println("KELILING");
        System.out.printf("- Segiempat : %.2f\n", totalKelilingSegiEmpat);
        System.out.printf("- Segitiga : %.2f\n", totalKelilingSegiTiga);

    }
}
