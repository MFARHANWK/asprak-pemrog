import scala.io.StdIn._

object P10B {
    def main(args: Array[String]): Unit = {
        val n = readInt()
        val num = readLine().trim.split(" ").map(_.toInt).toList.filter(_ >= 60)

        val grouped = num.groupBy(x => 
            if(x >= 85) "A"
            else if(x >= 70) "B"
            else "C"
        )

        val sorted = grouped.toList.sortWith((x,y) => x._2.size > y._2.size)
        val mapped = sorted.map((k,v) => (k, v.size))

        mapped.foreach((k,v) => println(s"$k $v"))
    }
}