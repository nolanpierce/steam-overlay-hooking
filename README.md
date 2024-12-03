### description
This project was aimed to render content using ImGui inside of a game without having to hook the games present function because it is heavily monitored and create a simple project for people to use that
leaves minimal traces. You can do this almost completely the same for every streaming service that loads a dll inside of a game along with discords in game overlay. 

### features
 - Hooks the present function for steams in game overlay using steams hooking function
 - uses directx 11
 - Uses ImGui to render a menu
 - serves as a base for any x64 steam game

### to know
- is currently using hardcoded offsets will change it to use pattern scanning offsets can be found be simply xreffing a string that saying "hooking vtable for swap chain" inside of steams rendering dll 
- if you plan on using this against anticheats you should xor all strings even inside ImGui and return spoof inside the present hook



