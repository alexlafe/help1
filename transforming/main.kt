fun main()
{
    val figures: Array<Movable>
    val rect: Transforming = Rect(2,1,5,3)
    val rect_m: Movable = Rect(2,1,5,3)

    val f: Figure = Rect(0,0,2,3)
    val f2: Figure = Circle(0,0,2)

    println(rect.rotate(RotateDirection.Clockwise,3, -3))
    println(rect.resize(2))
    println(rect_m.move(0,0))
}