object Elaborate extends App {
  (new chisel3.stage.ChiselStage).execute(args, Seq(
    chisel3.stage.ChiselGeneratorAnnotation(() => new SocTop()),
    firrtl.stage.RunFirrtlTransformAnnotation(new AddModulePrefix()),
    ModulePrefixAnnotation("ysyx_040091_")
  ))
}
