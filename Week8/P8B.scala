import scala.io.StdIn._

// Menggunakan HOF, kalau mau pake fungsi sendiri boleh juga
object P8B{
    def main(args: Array[String]): Unit = {
        val n = readInt();
        val num1 = readLine().trim.split(" ").map(_.toInt).toList
        val num2 = readLine().trim.split(" ").map(_.toInt).toList

        val max_mutlak_1 = num1.map(_.abs).max
        val max_mutlak_2 = num2.map(_.abs).max

        println(max_mutlak_1 * max_mutlak_2)

    }
}