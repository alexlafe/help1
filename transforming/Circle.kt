import kotlin.math.PI

class Circle (var x: Int, var y: Int, var radius: Int) : Figure(0), Transforming
{
    override fun area(): Float
    {
        return (radius * radius * PI).toFloat()
    }

    override fun resize(zoom: Int)
    {
        radius *= zoom
        println("Resize - radius: $radius")
    }

    override fun rotate(direction: RotateDirection, centerX: Int, centerY: Int)
    {
        if(centerX == x && centerY == y)
        {
            return
        }

        if(direction == RotateDirection.Clockwise)
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
