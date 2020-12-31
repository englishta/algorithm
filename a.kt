fun main(args:Array<String>) {
    println("hellow")
    println("hellow")
}

//******************<Macro>**************************
fun readInt() = readLine()!!.toInt()
fun readLong() = readLine()!!.toLong()
fun readDouble() = readLine()!!.toDouble()
fun readStr() = readLine()!!.toString()
fun read_Int() = readLine()!!.split(" ").map{it.toInt()}
fun read_Double() = readLine()!!.split(" ").map{it.toDouble()}
fun read_Long() = readLine()!!.split(" ").map{it.toLong()}
fun list() = readLine()!!.split(" ").map { it.toInt() }.toList()