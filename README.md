# ChangeMouseSpeed
This is a Program for Windows, changes mouse speed.
This is useful for people who use different mouse speed, and turns on and off enhanced pointer precision depending on computer usage, and is sick and tired of opening the mouse config screen(drawing, gaming, working, mouse vs track ball, etc).

Takes 4 values through commandline.
- speed
- threshold1
- threshold2
- Enhanced Pointer Precision.

When enhanced pointer precision is false(0), threshold1 and threshold2 is ignored.
When ehnaced pointer precision is enabled through mouse configuration GUI, threshold1 and threshold2 are set to 6 and 10 respectively.  
Below is how threshold works (taken from https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-mouse_event)
- The system applies two tests to the specified relative mouse motion when applying acceleration. If the specified distance along either the x or y axis is greater than the first mouse threshold value, and the mouse acceleration level is not zero, the operating system doubles the distance. If the specified distance along either the x- or y-axis is greater than the second mouse threshold value, and the mouse acceleration level is equal to two, the operating system doubles the distance that resulted from applying the first threshold test. It is thus possible for the operating system to multiply relatively-specified mouse motion along the x- or y-axis by up to four times.

I typically run this program through the attached batch file, which is config I use for track ball(mctb) and mouse(mcm).
