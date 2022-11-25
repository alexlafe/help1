fun main()
{
    val figures: Array<Movable>
    val rect: Transforming = Rect(4,3,4,2)
    val rect_m: Movable = Rect(4,3,4,2)

    val f: Figure = Rect(0,0,1,1)
    val f2: Figure = Circle(0,0,2)

    println(rect.rotate(RotateDirection.Clockwise,3, -3))
    println(rect.resize(2))
    println(rect_m.move(0,0))
}