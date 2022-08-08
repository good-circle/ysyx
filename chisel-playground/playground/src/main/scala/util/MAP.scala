import chisel3._
import chisel3.util._

object MaskData {
  def apply(oldData: UInt, newData: UInt, mask: UInt) = {
    (newData & mask) | (oldData & ~mask)
  }
}

object CSRRegMap {
  def DefaultMask = Fill(64, 1.U)

  def apply(addr: UInt, reg: UInt, wmask: UInt = DefaultMask,
            wfn: UInt => UInt = (x => x), rmask: UInt = DefaultMask) = (addr, (reg, wmask, wfn, rmask))

  def access(mapping: Map[UInt, (UInt, UInt, UInt => UInt, UInt)], addr: UInt, rdata: UInt,
             wdata: UInt, wen: Bool): Unit = {
    mapping.map { case (a, (r, wm, wfn, rm)) => {
      when (addr === a) {
        rdata := r & rm
      }
      if (wfn != null) {
        when (addr === a && wen) {
          r := wfn(MaskData(r, wdata, wm))
        }
      }
    }}
  }
}
