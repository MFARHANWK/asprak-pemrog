import scala.io.StdIn._
import scala.collection.immutable.LazyList.cons

object P9B {
	def main(args: Array[String]): Unit = {
	    val constraint = readLine().split(" ").map(_.toInt)
	    
	   // Yang ini bisa pakai exists yang mereturn boolean
	    val res = readLine().split(" ").map(_.toInt)
	    .contains(constraint(1))
	    println(if (res) 1 else 0)
	}
}