	const APPKEY = "WpBGCF1TfpePse3";
	const APPSECRET = "hitc5hKVHDU5OyfqlzCdIDWzf";
	const APPID =  "Smartfarm";

	var microgear = Microgear.create({
		gearkey: APPKEY,
		gearsecret: APPSECRET
	});
		
	microgear.on('message', function(topic,data) 
	{
		
		var res = data.split("=");//Temp1=12312
		
		if(res[0] == "Temp1")
		{
			document.getElementById("Temp1").innerHTML = res[1]+"°C";
			document.getElementById("Temp1").style.fontsize = "45px";
		}
		else if(res[0] == "Temp2")
		{
			document.getElementById("Temp2").innerHTML = res[1]+"°C";
			document.getElementById("Temp2").style.fontsize = "45px";
		}
	});

	microgear.on('connected', function()
	{
		microgear.setname('showtemp');
		document.getElementById("Temp1").style.fontsize = "45px";
		document.getElementById("Temp2").style.fontsize = "45px";
		document.getElementById("Temp2").style.fontSize = "large";
		document.getElementById("Temp1").innerHTML = "0°C";
		document.getElementById("Temp2").innerHTML = "0°C";

	});
	
	microgear.resettoken();
	microgear.connect(APPID);