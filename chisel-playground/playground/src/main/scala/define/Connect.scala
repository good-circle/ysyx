import chisel3._
import chisel3.util._

object Connect {
  def apply[T <: Data](left: DecoupledIO[T], right: DecoupledIO[T], rightOutFire: Bool, is_reflush: Bool) = {
    val valid = RegInit(false.B)
    val fire = left.valid && right.ready
    when (right.fire) { valid := false.B }
    when (fire) { valid := true.B }
    when (is_reflush) {valid := false.B}

    left.ready := right.ready
    right.bits := RegEnable(left.bits, fire)
    right.valid := valid
  }
}
