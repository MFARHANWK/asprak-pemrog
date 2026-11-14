import scala.io.StdIn._

object P9A {
	def main(args: Array[String]): Unit = {
	    val n = readInt()
	    val hasil = readLine().split(" ")
	    .map(x => x.toLong).filter(x => x % 2 == 0)
	    .map(x => x * x).sum
	    println(hasil)
	}
}