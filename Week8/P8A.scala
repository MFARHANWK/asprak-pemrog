import scala.io.StdIn._

// Menggunakan HOF, kalau mau pake fungsi sendiri boleh juga
object P8A{
    def main(args: Array[String]): Unit = {
        val n = readInt();
        val num = readLine().trim.split(" ").map(_.toInt).toList

        val min = num.min
        val max = num.max
        val sum = num.filter(x => x % 2 != 0).sum

        println(s"$min $max $sum")
    }
}