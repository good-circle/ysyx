import chisel3._
import chisel3.util._
import Define._

trait Config {
  val Sim = false
  val Soc = !Sim
  val MyEnv = true
  val RESET_VECTOR = if (Sim) "h80000000" else if (MyEnv) "h80000000" else "h30000000"
  val Difftest = Sim
  val SocDebug = false
}