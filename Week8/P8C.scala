import scala.io.StdIn._

def factorial(x : Int) : Int = {
    if(x == 1) return 1
    x * factorial(x-1)
}

object P8C{
    def main(args: Array[String]): Unit = {
        val n = readInt();
        println(factorial(n))
    }
}