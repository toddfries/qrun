<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<meta name="resource-type" content="document">
<title>
QRUN(1)</title>
</head>
<body>
<div class="mandoc">
<table summary="Document Header" class="head" width="100%">
<col width="30%">
<col width="30%">
<col width="30%">
<tbody>
<tr>
<td class="head-ltitle">
QRUN(1)</td>
<td class="head-vol" align="center">
OpenBSD Reference Manual</td>
<td class="head-rtitle" align="right">
QRUN(1)</td>
</tr>
</tbody>
</table>
<div class="section">
<h1 id="x4e414d45">NAME</h1> <b class="name">qrun</b> &#8212; <span class="desc">qemu wrapper</span></div>
<div class="section">
<h1 id="x53594e4f50534953">SYNOPSIS</h1><table class="synopsis">
<col style="width: 4.00ex;">
<col>
<tbody>
<tr>
<td>
qrun</td>
<td>
<b class="flag">&#45;i</b> <i class="arg">path</i> &#91;<span class="opt"><b class="flag">&#45;v</b></span>&#93; &#91;<span class="opt"><b class="flag">&#45;b</b> <i class="arg">interface</i></span>&#93; &#91;<span class="opt"><b class="flag">&#45;C</b> <i class="arg">path</i></span>&#93; &#91;<span class="opt"><b class="flag">&#45;c</b> <i class="arg">path</i></span>&#93; &#91;<span class="opt"><b class="flag">&#45;M</b> <i class="arg">mode</i></span>&#93; &#91;<span class="opt"><b class="flag">&#45;m</b> <i class="arg">memsize</i></span>&#93; &#91;<span class="opt"><b class="flag">&#45;n</b> <i class="arg">string</i></span>&#93; &#91;<span class="opt"><b class="flag">&#45;o</b> <b class="flag">bridge</b> | <b class="flag">console</b> | <b class="flag">netcfg</b></span>&#93; &#91;<span class="opt"><b class="flag">&#45;p</b> <i class="arg">path</i></span>&#93; &#91;<span class="opt"><b class="flag">&#45;s</b> <i class="arg">size</i></span>&#93; &#91;<span class="opt"><b class="flag">&#45;u</b> <i class="arg">user</i></span>&#93; &#91;<span class="opt"><i class="arg">qemu-options</i></span>&#93;</td>
</tr>
</tbody>
</table>
</div>
<div class="section">
<h1 id="x4445534352495054494f4e">DESCRIPTION</h1> <b class="name">qrun</b> requires at least the <b class="flag">&#45;i</b> option to specify the disk image. If a file does not exist, it will be created.<p>
By default, user mode network emulation will be used, so no further options are required for quick start usage. See the <i class="link-sec"><a class="link-sec" href="#x4558414d504c4553">EXAMPLES</a></i> section below for other simple usages.<p>
The options <b class="flag">&#45;b</b>, <b class="flag">&#45;n</b>, <b class="flag">&#45;o</b>, and <b class="flag">&#45;u</b> require <b class="name">qrun</b> to be executed as root, since they utilize privileged operations.<p>
The options are as follows:<p>
<dl style="margin-top: 0.00em;margin-bottom: 0.00em;" class="list list-tag">
<dt class="list-tag" style="margin-top: 0.00em;">
<b class="flag">&#45;b</b> <i class="arg">interface</i></dt>
<dd class="list-tag" style="margin-left: 6.00ex;">
Specifies the <a class="link-man">bridge(4)</a> interface to bridge to a guest network interface. If used multiple times, a new guest network interface will be created for each instance, bridged to the network interfaces in the order specified.<p>
</dd>
<dt class="list-tag" style="margin-top: 0.00em;">
<b class="flag">&#45;C</b> <i class="arg">path</i></dt>
<dd class="list-tag" style="margin-left: 6.00ex;">
Specifies the CD-ROM image or device from which to read blocks of data when presenting the guest OS with a simulated <a class="link-man">atapiscsi(4)</a> CD-ROM device.<p>
</dd>
<dt class="list-tag" style="margin-top: 0.00em;">
<b class="flag">&#45;c</b> <i class="arg">path</i></dt>
<dd class="list-tag" style="margin-left: 6.00ex;">
Identical to the <b class="flag">&#45;C</b> option, but additionally boots the guest OS from the simulated CD-ROM device.<p>
</dd>
<dt class="list-tag" style="margin-top: 0.00em;">
<b class="flag">&#45;i</b> <i class="arg">path</i></dt>
<dd class="list-tag" style="margin-left: 6.00ex;">
Specifies the file or device from which to read blocks of data when presenting the guest OS with a simulated <a class="link-man">wd(4)</a> device.<p>
</dd>
<dt class="list-tag" style="margin-top: 0.00em;">
<b class="flag">&#45;M</b> <i class="arg">mode</i></dt>
<dd class="list-tag" style="margin-left: 6.00ex;">
Changes the machine presented to the guest OS. By default, an i386 machine is presented. The only other valid mode is amd64.<p>
</dd>
<dt class="list-tag" style="margin-top: 0.00em;">
<b class="flag">&#45;m</b> <i class="arg">memsize</i></dt>
<dd class="list-tag" style="margin-left: 6.00ex;">
Alters the memory presented to the guest OS. By default, <i class="arg">memsize</i> is 128m.<p>
</dd>
<dt class="list-tag" style="margin-top: 0.00em;">
<b class="flag">&#45;n</b> <i class="arg">string</i></dt>
<dd class="list-tag" style="margin-left: 6.00ex;">
A string passed to <a class="link-man">ifconfig(8)</a> to configure the <a class="link-man">tun(4)</a> device. This is for routing <a class="link-man">qemu(1)</a> sessions natively and/or NAT-ing them via <a class="link-man">pf(4)</a>. Like the <b class="flag">&#45;b</b> option, multiple <b class="flag">&#45;n</b> options may be specified, each one coinciding with an interface presented to the guest OS, in the order specified. The <b class="flag">&#45;n</b> and <b class="flag">&#45;b</b> options may be both used if desired.<p>
</dd>
<dt class="list-tag" style="margin-top: 0.00em;">
<b class="flag">&#45;o</b> <i class="arg">bridge=interface,model=nicmodel,macaddr=52:54:01:00:XX:XX</i></dt>
<dd class="list-tag" style="margin-left: 6.00ex;">
</dd>
<dt class="list-tag" style="margin-top: 0.00em;">
<b class="flag">&#45;o</b> <i class="arg">netcfg=string,model=nicmodel,macaddr=52:54:01:00:XX:XX</i></dt>
<dd class="list-tag" style="margin-left: 6.00ex;">
</dd>
<dt class="list-tag" style="margin-top: 0.00em;">
<b class="flag">&#45;o</b> <i class="arg">console=com0,monitor=stdio,serial=unix,vnc=[::]:3</i></dt>
<dd class="list-tag" style="margin-left: 6.00ex;">
</dd>
<dt class="list-tag" style="margin-top: 0.00em;">
<b class="flag">&#45;o</b> <i class="arg">controllertype=&lt;ctype&gt;</i></dt>
<dd class="list-tag" style="margin-left: 6.00ex;">
Provides a more advanced usage of the <b class="flag">&#45;b</b> and <b class="flag">&#45;n</b> options as well as enabling a serial console to be presented at a terminal prompt. &lt;ctype&gt; can be one of<p>
</dd>
<dt class="list-tag" style="margin-top: 0.00em;">
<i class="arg">ahci</i></dt>
<dd class="list-tag" style="margin-left: 6.00ex;">
</dd>
<dt class="list-tag" style="margin-top: 0.00em;">
<i class="arg">isa-ide</i></dt>
<dd class="list-tag" style="margin-left: 6.00ex;">
</dd>
<dt class="list-tag" style="margin-top: 0.00em;">
<i class="arg">lsi53c895a</i></dt>
<dd class="list-tag" style="margin-left: 6.00ex;">
</dd>
<dt class="list-tag" style="margin-top: 0.00em;">
<i class="arg">virtio-blk-pci</i></dt>
<dd class="list-tag" style="margin-left: 6.00ex;">
</dd>
<dt class="list-tag" style="margin-top: 0.00em;">
<i class="arg">usb-storage</i></dt>
<dd class="list-tag" style="margin-left: 6.00ex;">
If combined with the <b class="flag">&#45;p</b> option and an <i class="file">/etc/boot.conf</i> file containing &#8220;set tty com0&#8221;, a system may be booted to a serial console in a terminal without requiring graphics. This can be especially useful for running inside <a class="link-man">tmux(1)</a>.<p>
The <i class="arg">interface</i> option to bridge may be a physical interface, such as em0, or a special notation:<p>
<pre style="margin-left: 5.00ex;" class="lit display">
<i class="arg">group:string</i></pre>
<p>
This special notation permits multiple qrun instances to be bridged together, by adding the string to the interface group of the <a class="link-man">bridge(4)</a> instead of bridging to a physical interface. This mainly for the <a class="link-man">qnet(1)</a> script, but advanced users may choose to use it themselves. The string is limited by interface group limitations and therefore may not end in a number.<p>
</dd>
<dt class="list-tag" style="margin-top: 0.00em;">
<b class="flag">&#45;p</b> <i class="arg">path</i></dt>
<dd class="list-tag" style="margin-left: 6.00ex;">
Specifies the tftpboot dir from which to <a class="link-man">pxeboot(8)</a> the guest OS. The guest virtual machines BIOS will TFTP the file &#8220;pxeboot&#8221; from the <i class="arg">path</i> specified and start executing it as a real system would.<p>
</dd>
<dt class="list-tag" style="margin-top: 0.00em;">
<b class="flag">&#45;s</b> <i class="arg">size</i></dt>
<dd class="list-tag" style="margin-left: 6.00ex;">
Specifies the size of the disk image to create, if <b class="name">qrun</b> is auto-creating the disk image.<p>
</dd>
<dt class="list-tag" style="margin-top: 0.00em;">
<b class="flag">&#45;u</b> <i class="arg">user</i></dt>
<dd class="list-tag" style="margin-left: 6.00ex;">
Runs <a class="link-man">qemu(1)</a> as user <i class="arg">user</i>. This is recommended if one of the options requiring root privileges is used, as the environment will be set up then the fdpass program will drop privileges to the user specified and qemu will not be running as root.<p>
</dd>
<dt class="list-tag" style="margin-top: 0.00em;">
<b class="flag">&#45;v</b></dt>
<dd class="list-tag" style="margin-left: 6.00ex;">
Provides verbose information while setting up <a class="link-man">bridge(4)</a> and <a class="link-man">tun(4)</a> interfaces as well as showing the <a class="link-man">qemu(1)</a> command line used when starting qemu.</dd>
</dl>
</div>
<div class="section">
<h1 id="x454e5649524f4e4d454e54">ENVIRONMENT</h1> No environment variables are useful at this time.</div>
<div class="section">
<h1 id="x4558414d504c4553">EXAMPLES</h1> Here are examples on how to use <b class="name">qrun</b>.<p>
The most basic simple usage would be to install a guest OS with user mode networking:<p>
<blockquote style="margin-top: 0.00em;margin-bottom: 0.00em;">
<div class="display">
<code class="lit">$ qrun -i test.hd -c cd47.iso</code></div>
</blockquote>
<p>
After the installation, one would issue &#8220;quit&#8221; at the &#8220;(qemu)&#8221; prompt and then start <a class="link-man">qemu(1)</a> subsequently via:<p>
<blockquote style="margin-top: 0.00em;margin-bottom: 0.00em;">
<div class="display">
<code class="lit">$ qrun -i test.hd</code></div>
</blockquote>
<p>
Another common way to use <b class="name">qrun</b> would be to bridge the native Ethernet to a <a class="link-man">qemu(1)</a> guest's network interface:<p>
<blockquote style="margin-top: 0.00em;margin-bottom: 0.00em;">
<div class="display">
<code class="lit">$ sudo qrun -u $USER -i test.hd -b em0</code></div>
</blockquote>
<p>
This sets up a <a class="link-man">bridge(4)</a> interface to connect the <a class="link-man">em(4)</a> interface of the native system and the <a class="link-man">tun(4)</a> interface of the <a class="link-man">qemu(1)</a> guest OS.<p>
The third common way to use <b class="name">qrun</b> would be to route the <a class="link-man">qemu(1)</a> guest's network interface:<p>
<blockquote style="margin-top: 0.00em;margin-bottom: 0.00em;">
<div class="display">
<code class="lit">$ sudo qrun -u $USER -i test.hd -n 10.0.1.1/24</code></div>
</blockquote>
<p>
This would set up a <a class="link-man">tun(4)</a> interface with &#8220;10.0.1.1 netmask 255.255.255.0&#8221; and it would be up to the user to run <a class="link-man">dhcpd(8)</a> on the <a class="link-man">tun(4)</a> interface connected to the <a class="link-man">qemu(1)</a> guest OS.<p>
One final advanced example that most people will not want to bother with but can show the power of <b class="name">qrun</b>:<p>
<pre style="margin-left: 5.00ex;" class="lit display">
$ sudo qrun -u $USER -i `pwd`/test.hd &#92; 
  -o bridge=em0,model=rtl8139,macaddr=52:54:01:00:XX:XX &#92; 
  -o console=com0 &#92; 
  -- &#92; 
  -serial telnet:127.0.0.1:30000,server,nowait &#92; 
  -monitor telnet:127.0.0.1:40000,server,nowait &#92; 
  -daemonize</pre>
</div>
<div class="section">
<h1 id="x53454520414c534f">SEE ALSO</h1> <a class="link-man">fdpass(1)</a>, <a class="link-man">qemu(1)</a>, <a class="link-man">bridge(4)</a>, <a class="link-man">pf(4)</a>, <a class="link-man">tun(4)</a></div>
<div class="section">
<h1 id="x484953544f5259">HISTORY</h1> This utility is entirely a new creation from <span class="author">Todd T. Fries</span> &#60;todd@fries.net&#62;, inspired by <span class="author">Bob Beck</span> &#60;beck@openbsd.org&#62;.</div>
<table summary="Document Footer" class="foot" width="100%">
<col width="50%">
<col width="50%">
<tbody>
<tr>
<td class="foot-date">
April 24, 2014</td>
<td class="foot-os" align="right">
OpenBSD 5.5</td>
</tr>
</tbody>
</table>
</div>
</body>
</html>

