# ChangeMouseSpeed
This is a Program for Windows to changes mouse speed.
This app is useful for people who use different mouse speed based on computer usage, such as drawing, gaming, working, switching to track ball, etc.

Takes 4 parameters through commandline.
- speed
- threshold1
- threshold2
- Enhanced Pointer Precision
Speed is how much the cursor moves.
Enabling Enhanced Pointer Precision will cause mouse cursor to travel more pixels when mouse is moved faster.  When enhanced pointer precision is off, mouse movement distance in screen will remain same regardless of the physical mouse movement speed.
Below is how the two threshold works (taken from https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-mouse_event)
- The system applies two tests to the specified relative mouse motion when applying acceleration. If the specified distance along either the x or y axis is greater than the first mouse threshold value, and the mouse acceleration level is not zero, the operating system doubles the distance. If the specified distance along either the x- or y-axis is greater than the second mouse threshold value, and the mouse acceleration level is equal to two, the operating system doubles the distance that resulted from applying the first threshold test. It is thus possible for the operating system to multiply relatively-specified mouse motion along the x- or y-axis by up to four times.
- When enhanced pointer precision is disabled(0), threshold1 and threshold2 is ignored.
- When ehnaced pointer precision is enabled(1) through mouse configuration GUI, threshold1 and threshold2 are set to 6 and 10 respectively.  

I typically run this program through the attached batch file, which is config I use for track ball(mctb) and mouse(mcm).
