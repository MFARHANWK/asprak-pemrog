import scala.io.StdIn._

object P10A {
    def main(args: Array[String]): Unit = {
        val input = readLine().trim.split(" ").map(_.toInt).toList
        val num = readLine().trim.split(" ").map(_.toLong).toList

        val k = input(1)

        val filtered_squared = num.filter(x => x % 2 == 0 && x > 0).map(x => x * x)
        val sorted = filtered_squared.sorted.reverse
        val res = sorted.take(k).sum
        println(res)

    }
}