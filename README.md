A simple Automotive Grade Linux app example
===========================================

This project replaces poi@0.1 app in agl-demo-platform. See [config.xml](config.xml.in)

In [AGL SDK environment](http://docs.automotivelinux.org/docs/getting_started/en/dev/reference/setup-sdk-environment.html):

    git clone git@github.com:propella/agl-hello.git
    cd agl-hello
    source /xdt/sdk/environment-setup-xxx
    cmake
    make
    scp package/agl-hello.wgt root@(your device):.

In your device:

    afm-util uninstall poi@0.1
    afm-util install agl-hello.wgt
    
Reboot and click POINT OF INTEREST icon.

Japanese article: http://qiita.com/propella/items/0258163c18a506f12a55
