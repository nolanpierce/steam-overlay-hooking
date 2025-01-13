### description
This project was aimed to render content using ImGui inside of a game without having to hook the games present function because it is heavily monitored and to show the developers how simple it is to do. It needs to be fixed and hopefully 
from this project we can fix it. The crazy part is you can do this almost completely the same for every streaming service that loads a dll inside of a game along with discords in game overlay. 

### Reason For Interest
I have mainly stuck to the kernel and the more low level side of windows vulnerablity development and came across someone rendering a dll inside of the game to render visuals and execute milicous code inside protected games. So obviously this got me thinking. The person doing this definitly wasnt the brightest so it scratched the itch for me and I had to dive into it. Thankfully this post will alarm anticheat developers and the will do better checks for this.

### Discovery
I discovered how simple this is to do and how it is a copy pastabale solution so it needs to be stopped. You simply have to xref one string in a dissassmbler and u get two functions after f5ing to get spuedo code that are over powered you essentially are system calling their hooking functions so already this doesnt trip many flags the main flag being the return address add return spoofing into the mix there legit is probably no way of this being detected against modern anticheats like EAC, BE, etc...


### features
 - Completely stream proof if done correctly
 - Hooks the present function for steams in game overlay using steams hooking function (all software the streams or creates an overlay should have these two functions)
 - uses directx 11
 - Uses ImGui to render a menu

### Possible Fixes
This currently is working without a return spoofer so if we are going to be minimal here it would be to just validate the return address of the function. But if we dive deeper than this we can also do simple gadget checks to find hooks, at least common hooking methods like, trampolines, code caves, and the list goes on.


### Summery
This is just a very very simple quick write up, only intended to spark ideas on prevention. If you have any great ideas and would like to discuss them with me pm me on discord @sudopacmann




