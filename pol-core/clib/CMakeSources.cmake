set (clib_sources
  #sorted !
  CMakeSources.cmake 
  Debugging/ExceptionParser.cpp
  Debugging/ExceptionParser.h
  Debugging/LogSink.cpp
  Debugging/LogSink.h
  Header_Windows.h
  Program/ProgramConfig.cpp
  Program/ProgramConfig.h
  Program/ProgramMain.cpp
  Program/ProgramMain.h
  StdAfx.h
  binaryfile.cpp 
  binaryfile.h
  bitutil.h
  boostutils.cpp 
  boostutils.h
  cfgelem.h
  cfgfile.cpp 
  cfgfile.h
  cfgsect.cpp
  cfgsect.h
  clib.h
  clib_MD5.cpp
  clib_MD5.h
  clib_endian.h
  clib_utils.cpp 
  clibopt.h
  clibopt.h
  compilerspecifics.h
  dirfunc.h
  esignal.cpp
  esignal.h
  fdump.cpp 
  fdump.h
  filecont.cpp
  filecont.h
  fileutil.cpp 
  fileutil.h
  fixalloc.h
  formatfwd.h
  iohelp.cpp
  iohelp.h
  kbhit.cpp
  kbhit.h
  logfacility.cpp
  logfacility.h
  maputil.h
  message_queue.h
  mlog.cpp 
  mlog.h
  network/sckutil.cpp 
  network/sckutil.h
  network/singlepoller.h
  network/singlepollers/pollingwithpoll.h
  network/singlepollers/pollingwithselect.h
  network/sockets.h
  network/socketsvc.cpp 
  network/socketsvc.h
  network/wnsckt.cpp
  network/wnsckt.h
  opnew.cpp
  opnew.h
  passert.cpp
  passert.h
  random.cpp 
  random.h
  rawtypes.h
  refptr.h
  spinlock.h
  stlutil.h
  stracpy.cpp
  streamsaver.cpp
  streamsaver.h
  strset.cpp 
  strset.h
  strutil.cpp
  strutil.h
  threadhelp.cpp
  threadhelp.h
  timer.cpp
  timer.h
  tracebuf.cpp
  tracebuf.h
  wallclock.cpp
  wallclock.h
  weakptr.h
  xmain.cpp
  #pol_global_config_win.h
  #vld.h
)
if(windows)
  set (clib_sources ${clib_sources}
    NTService.cpp
    NTService.h
    StdAfx.cpp
    forspcnt.cpp
    mdump.cpp
    mdump.h
    mdumpimp.h
    msjexhnd.cpp
    msjexhnd.h
    ntservmsg.h
    strexcpt.cpp #TODO: remove as default? 
    strexcpt.h
  )
endif()
