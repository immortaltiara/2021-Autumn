# 基础知识学习

1. 这段时间一直在补返校前的作业，没学太多新东西

2. 通过构造函数精简ini调用

   原:

   ```C#
   a.IniRead("Achievements", "TenSecondsOver", "./setting.ini")
   a.IniWrite("Achievements","StartGameTime","123", "./setting.ini")
   ```

   修改后:

   ```C#
   public Ini(string filePath)
   {
   	this.Path = filePath;
   }
   
   a.IniRead("Achievements", "TenSecondsOver")
   a.IniWrite("Achievements","StartGameTime","123")
   ```

3. 抓到的一些b站接口

   ```C#
   https://api.bilibili.com/x/v2/reply/add
   post数据:"oid=" + Data.oid + "&type=1&message=" + Data.message + "&plat=1&ordering=heat&jsonp=jsonp&csrf=" + Data.csrf
   评论视频
   
   https://api.bilibili.com/x/v2/reply/add
   post数据:"oid=" + Data.oid + "&type=17&message=" + Data.message + "&plat=1&ordering=heat&jsonp=jsonp&csrf=" + Data.csrf
   评论无图动态
   
   https://api.bilibili.com/x/v2/reply/add
   post数据:"oid=" + Data.oid + "&type=11&message=" + Data.message + "&plat=1&ordering=heat&jsonp=jsonp&csrf=" + Data.csrf
   评论有图动态
   
   https://api.vc.bilibili.com/dynamic_repost/v1/dynamic_repost/repost
   post数据:"uid=" + Data.uid + "&dynamic_id=" + Data.oid + "&content=" + Data.message + "&extension=" + "{" + "\"emoji_type\":1" + "}" + "&at_uids= &ctrl=[]&csrf_token=" + Data.csrf + "&csrf=" + Data.csrf
   转发动态
       
   https://api.bilibili.com/x/relation/modify
   post数据:"fid=" + Data.uid + "&act=1&re_src=11&jsonp=jsonp&csrf=" + Data.csrf
   关注
   
   https://api.vc.bilibili.com/dynamic_like/v1/dynamic_like/thumb
   post数据:"uid=" + Data.uid + "&dynamic_id=" + Data.oid + "&up=1&csrf_token=" + Data.csrf + "&csrf=" + Data.csrf
   点赞
       
   其中:Data.oid为动态的长、短id，视频的av、bv号，所关注的用户uid
       Data.message为输入的内容
       Data.csrf为账号的web验证信息，每次退出账号会重置
       Data.uid为本账号的uid
       
   顺便后来才发现C#好像可以用$"uid={Data.uid}&dynamic_id={Data.oid}"来提高代码可读性
   ```

4. 全局快捷键

   ```C#
   HotKey.RegisterHotKey(Handle, 137, HotKey.KeyModifiers.Alt, Keys.X);
   HotKey.UnregisterHotKey(Handle, 137);
    
   protected override void WndProc(ref Message m)
   {
   
       const int WM_HOTKEY = 0x0312;
       //按快捷键 
       switch (m.Msg)
       {
           case WM_HOTKEY:
               switch (m.WParam.ToInt32())
               {
                   case 137:
                       {
                           WindowState = FormWindowState.Normal;
                           ShowInTaskbar = true;
                       }
                       break;
               }
               break;
       }
       base.WndProc(ref m);
   }
   
   class HotKey
   {
       [System.Runtime.InteropServices.DllImport("user32.dll", SetLastError = true)]
       public static extern bool RegisterHotKey(IntPtr hWnd,int id,KeyModifiers fsModifiers,Keys vk);
       [System.Runtime.InteropServices.DllImport("user32.dll", SetLastError = true)]
       public static extern bool UnregisterHotKey(IntPtr hWnd,int id);
       [Flags()]
       public enum KeyModifiers
       {
           None = 0,
           Alt = 1,
           Ctrl = 2,
           Shift = 4,
           WindowsKey = 8
       }
   }
   
   一个小bug(特性?):在隐藏了主窗口，即
           WindowState = FormWindowState.Minimized;
           ShowInTaskbar = false;
   后，注册的快捷键会失效，需要把注册快捷键的代码放在其后面
   ```

# 主要任务

1. 敌人AI功能模块

2. 背包系统功能模块

   **具体请看代码与视频**（由于一些bug，AI敌人存在时→背包物品拖动时无法显示）

   代码地址:[Release 1.0 · acceleratism/test3.30 (github.com)](https://github.com/acceleratism/test3.30/releases/tag/ver)

   视频地址:[Release 1.0 · acceleratism/test3.30 (github.com)](https://github.com/acceleratism/test3.30/releases/tag/ver)

# 游戏策划

核心玩法：2D休闲解谜

整体框架：可以在过去与现在两个时间线之间切换，并以此通过障碍物与敌人，收集道具，完成解谜，场景设计可以参考i wanna

游戏功能模块：简单的敌人AI(左右移动，发射子弹),背包系统(拥有道具靠近对应场景自动使用)，图鉴(或成就)模块

