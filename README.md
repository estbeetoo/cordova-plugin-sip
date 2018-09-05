# cordova-plugin-sip
<h2>SIP plugin for Cordova & Phonegap Apps (IOS and Android)</h2>

<h3>IOS</h3>

<h4>Build Settings -> Header Search Paths</h4>

```
    "$(SRCROOT)/YOURPROJECTNAME/Plugins/cordova-plugin-sip/include"
    "$(SRCROOT)/YOURPROJECTNAME/Plugins/cordova-plugin-sip/include/belle-sip"
    "$(SRCROOT)/YOURPROJECTNAME/Plugins/cordova-plugin-sip/include/ortp"
    "$(SRCROOT)/YOURPROJECTNAME/Plugins/cordova-plugin-sip/include/linphone"
    "$(SRCROOT)/YOURPROJECTNAME/Plugins/cordova-plugin-sip/include/mediastreamer2"
```

<h4>You must import these files in the  Bridging Header File</h4>

```
    #include "Plugins/cordova-plugin-sip/include/linphone/lpconfig.h"
    #include "Plugins/cordova-plugin-sip/include/linphone/linphonecore.h"
    #include "Plugins/cordova-plugin-sip/include/linphone/linphonecore_utils.h"
```

<h4>IOS Permissions</h4>
  
You must include following permissions
```
        <key>NSCameraUsageDescription</key>
        <string>Description Why you use this permission</string>
        <key>NSMicrophoneUsageDescription</key>
        <string>Description Why you use this permission</string>
```


<h3>Android </h3>

Deploy and Run!



<h3>Usage</h3>

```
var sipManager = {
    register: function () {
        cordova.plugins.sip.login('102', '102', '192.168.1.22:5060', sipManager.events, sipManager.events);
    },
    call: function () {
        cordova.plugins.sip.call('sip:111@192.168.1.111:5060', '203', function (e) {
        }, function (e) {
        })
    },

    hangup: function () {
        cordova.plugins.sip.hangup(function (e) {}, function (e) {})
    },
               
    accept: function () {
        cordova.plugins.sip.accept(function (e) {}, function (e) {})
    },
   
    dtmf: function (dtmf) {
        cordova.plugins.sip.sendDtmf(dtmf, function (e) {}, function (e) {})
    },

    events: function (event) {
        console.log(event);

        var e = JSON.parse(event).status;

        if (e == 'RegistrationOk') {
            alert("RegistrationOk");
        }
        if (e == 'RegistrationError') {
            alert("Registration Failed!");
        }
        if (e == 'CallIncomingReceived') {
            var r = confirm("Incoming Call");
            if (r == true) {
                console.log("call from user " + JSON.parse(event).username);
                sipManager.accept();
            } else {
                sipManager.hangup();
            }
        }
        if (e == 'CallError') {
            alert("Call Error!");
        }
        if (e == 'CallEnd') {
            alert("Call End!");
        }
    }
}
```

<h3>Event message</h3>

Event message it is json.

Fromat json response {"status": TYPE }

<h4>Registration type for json status </h4>

```   
RegistrationNone -> Initial state for registrations 
RegistrationProgress -> Registration is in progress 
RegistrationOk -> Registration is successful 
RegistrationCleared -> Unregistration succeeded 
RegistrationFailed</h4>  
```

<h4>Call type for json status</h4>

```   
CallIdle -> Initial call state 
CallIncomingReceived -> This is a new incoming call  ( For this type, added new field exsample {"status":"CallIncomingReceived", "username":"username"} )
CallOutgoingInit -> An outgoing call is started 
CallOutgoingProgress -> An outgoing call is in progress 
CallOutgoingRinging -> An outgoing call is ringing at remote end 
CallOutgoingEarlyMedia -> An outgoing call is proposed early media 
CallConnected -> Connected, the call is answered 
CallStreamsRunning -> The media streams are established and running
CallPausing -> The call is pausing at the initiative of local end 
CallPaused -> The call is paused, remote end has accepted the pause 
CallResuming -> The call is being resumed by local end
CallRefered -> The call is being transfered to another party, resulting in a new outgoing call to follow immediately
CallError -> The call encountered an error
CallEnd -> The call ended normally
CallPausedByRemote -> The call is paused by remote end
CallUpdatedByRemote -> The call's parameters change is requested by remote end, used for example when video is added by remote 
CallIncomingEarlyMedia -> We are proposing early media to an incoming call 
CallUpdating -> A call update has been initiated by us 
CallReleased -> The call object is no more retained by the core 
CallEarlyUpdatedByRemote -> The call is updated by remote while not yet answered (early dialog SIP UPDATE received).
CallEarlyUpdating -> We are updating the call while not yet answered (early dialog SIP UPDATE sent)
```

<h4>Other type for json status</h4>

SendDtmf -> Initial call state 


