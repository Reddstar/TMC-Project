@echo off

rem  ----------------------------------------------------------------------
rem  Producing the dynamical library for the simulation of the application 
rem  It will be loaded by java.
rem  ----------------------------------------------------------------------

call %~dp0..\SynthesisEnv.bat

set ADR_EXPORT_RES=%LD_RES%\export

set ADR_liaison=%LD_DEMO%\demo\Liaison.dir
set ADR_JavaCodeDemo=%LD_DEMO%\demo\Classes.dir
set ADR_spec_liaison=Spec_Liaison.dir

javac -deprecation -d %ADR_JavaCodeDemo% %ADR_JavaCodeDemo%\JAVA.dir\*.java
javac -deprecation -classpath %ADR_JavaCodeDemo%;Demo -d Demo Demo\vt.java

rem  System dependent
set DEMOLIB=VTAGVLIB.dll
%MAKE% %1  /f Makefile.win
