fun main(args:Array<String>) {
    var (n, w) = read_Int()
    println(n/w)
}

//******************<Macro>**************************
fun readInt() = readLine()!!.toInt()
fun readLong() = readLine()!!.toLong()
fun readDouble() = readLine()!!.toDouble()
fun readStr() = readLine()!!.toString()
fun read_Int() = readLine()!!.split(" ").map{it.toInt()}
fun read_Double() = readLine()!!.split(" ").map{it.toDouble()}
fun read_Long() = readLine()!!.split(" ").map{it.toLong()}
fun read_list_int() = readLine()!!.split(" ").map { it.toInt() }.toList()