	const APPKEY = "WpBGCF1TfpePse3";
	const APPSECRET = "hitc5hKVHDU5OyfqlzCdIDWzf";
	const APPID =  "Smartfarm";

	var microgear = Microgear.create({
		gearkey: APPKEY,
		gearsecret: APPSECRET
	});

	function switchPress()
	{
		if(document.getElementById("cube-switch").className == "cube-switch active"){
			microgear.chat("Client1","OFF");
		}else if(document.getElementById("cube-switch").className == "cube-switch"){
			microgear.chat("Client1","ON");
		}
	}
	function switchPress1()
	{
		if(document.getElementById("cube-switch1").className == "cube-switch active"){
			microgear.chat("Client2","OFF");
		}else if(document.getElementById("cube-switch1").className == "cube-switch"){
			microgear.chat("Client2","ON");
		}
	}
	
	function b_up_function()
	{
		microgear.chat("Client3","UP");
		//alert("UP");
	}
	function b_down_function()
	{
		microgear.chat("Client3","DOWN");
		//alert("DOWN");
	}
	function b_left_function()
	{
		microgear.chat("Client3","LEFT");
		//alert("LEFT");
	}
	function b_right_function()
	{
		microgear.chat("Client3","RIGHT");
		//alert("RIGHT");
	}
		
	microgear.on('message', function(topic,data) 
	{
		if(data=="ON1")
		{
			document.getElementById("cube-switch").className = "cube-switch active";
		}
		else if(data=="OFF1")
		{
			document.getElementById("cube-switch").className = "cube-switch";
		}
		
		else if(data=="ON2")
		{
			document.getElementById("cube-switch1").className = "cube-switch active";
		}
		else if(data=="OFF2")
		{
			document.getElementById("cube-switch1").className = "cube-switch";
		}
		
		var res = data.split("=");//Temp1=12312
		
		if(res[0] == "Temp1")
		{
			document.getElementById("Temp1").innerHTML = "อุณหภูมิ "+res[1]+" องศา";
		}
		else if(res[0] == "Temp2")
		{
			document.getElementById("Temp2").innerHTML = "อุณหภูมิ "+res[1]+" องศา";
		}
	});

	microgear.on('connected', function()
	{
		microgear.setname('controllerplug');
		document.getElementById("cube-switch").className = "cube-switch active";
		document.getElementById("cube-switch").style.display = "block";
		
		document.getElementById("cube-switch1").className = "cube-switch active";
		document.getElementById("cube-switch1").style.display = "block";
		
		document.getElementById("Temp1").innerHTML = "อุณหภูมิ 01 องศา";
		document.getElementById("Temp2").innerHTML = "อุณหภูมิ 02 องศา";
	});
	
	microgear.resettoken();
	microgear.connect(APPID);