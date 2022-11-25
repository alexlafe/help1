class Square(var x: Int, var y: Int, var width: Int) : Figure(0), Transforming
{
    override fun area(): Float
    {
        return (width * width).toFloat()
    }

    override fun resize(zoom: Int)
    {
        width *= zoom
        println("Resize - width: $width")
    }

    override fun rotate(direction: RotateDirection, centerX: Int, centerY: Int)
    {
        if (centerX == x && centerY == y)
        {
            return
        }

        if (direction == RotateDirection.Clockwise)
        {
            x = y - centerY + centerX.also{ y = -x + centerX + centerY}
        }
        else
        {
            x = - y + centerY + centerX.also{ y = x - centerX + centerY}
        }

        println("Rotate - x: $x, y: $y")
    }
}