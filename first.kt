fun main(args:Array<String>) {
    var n = readInt()
    val list = read_list_int()
    var ary = Array(100003){it*0}

    for(t in list){
        if(t>0) ary[t-1]+=1
        ary[t+1]+=1
        ary[t]+=1
    }
    var M = 0
    for(x in ary){
        if(x > M) M = x
    }
    println(M)
}


// region kokokara template dayo (^o^)
fun readInt() = readLine()!!.toInt()
fun readLong() = readLine()!!.toLong()
fun readDouble() = readLine()!!.toDouble()
fun readStr() = readLine()!!.toString()
fun read_Int() = readLine()!!.split(" ").map{it.toInt()}
fun read_Double() = readLine()!!.split(" ").map{it.toDouble()}
fun read_Long() = readLine()!!.split(" ").map{it.toLong()}
fun read_list_int() = readLine()!!.split(" ").map { it.toInt() }.toList()