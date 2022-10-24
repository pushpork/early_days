# Early Days

Early on in high school I was learning to program in C++, and had just
discovered OpenGL as a way of actually putting something on screen. I know it
must've been _very_ early in high school because when trying to figure out how
to rotate my player's movement and just interpolating between fully horizontal
and fully vertical resulted in short movements when going at 45 degrees; I knew
I needed something that preserved the total length and didn't yet know that was
trigonometry - which hadn't been covered at school yet. My limited knowledge
caused me to give up on a lot of these early projects.

In any case, looking back I've certainly learnt a lot and become a much more
competent programmer. It's frustrating to see how tiny pieces of knowledge were
roadblocks to me completing these projects.

Enter this project: starting with a basic "hello world" graphics demo, that I
would have been able to create way back when, what small incremental changes
can I implement that move the project forward. These changes should be
something I could realistically of understood or have explained to me back
then. As the project progresses I may be more lax on that requirement.

Each change will be committed and a paragraph of text, and maybe a screenshot
or two, will be added to this document, explaining the rationale for the
change.

The following concessions and restrictions will be made:
- **GLFW**. I'm pretty sure I was writing straight Win32 back then, but
  this isn't a project focused on purity and besides: I use linux almost
  exclusively now.
- **C, not C++**. I prefer C and I was really using a more procedural style at
  that point anyway
- **Fixed-function**. If I used shaders then a lot of these features would be
  trivial to implement. I intend to stick to a simple OpenGL immediate mode and
  see how far I can push it... it'll be more fun that way.
- **Not overly granular**. If a change lends itself to a natural refactor then
  I can gloss over the first version and just commit the cleaned up version;
  just as long as I write about the refactor in the accompanying paragraph.

## Building
This project is a single executable, with minimal requirements as far as
libraries and compilers go. I will provide a standard Makefile, that uses
pkg-config, meaning it should build on most *nix systems - possibly even WSL.
If not then just throw all the source into a project and add the required libs.

### tl;dr
```
make
```

## v1 - Starting point
![Screenshot of version 1](/screenshots/1-1.png)

I created this version from memory. I remember it was untextured, using vertex
colours for lighting. The arrow keys move the level around, keeping the player
centre screen.

There are so many issues with this already. Firstly the mesh is drawn using
immediate mode; it was painful hand-coding coordinates even for this little
demo scene - no wonder I gave up on this. The mesh is also covered in
T-Junctions and the player movement is tied to the framerate.