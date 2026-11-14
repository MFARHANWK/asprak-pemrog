import scala.io.StdIn._

object P9C {
	def main(args: Array[String]): Unit = {
		val input = readLine().toLowerCase.split(" ")
		val n = input(0).toInt
		val c = input(1)
		
		val words = (1 to n).map(_=>readLine()).toList
		val result = words.map(_.toLowerCase()).filter(_.contains(c)).toList.size

		println(result)
	}
}