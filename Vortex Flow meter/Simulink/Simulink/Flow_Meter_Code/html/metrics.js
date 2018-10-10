function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.var["rtDW"] = {file: "C:\\Users\\Vishnu\\AppData\\Local\\Packages\\microsoft.windowscommunicationsapps_8wekyb3d8bbwe\\LocalState\\Files\\S0\\294\\Flow_Meter_ert_rtw\\Flow_Meter.c",
	size: 16};
	 this.metricsArray.var["rtM_"] = {file: "C:\\Users\\Vishnu\\AppData\\Local\\Packages\\microsoft.windowscommunicationsapps_8wekyb3d8bbwe\\LocalState\\Files\\S0\\294\\Flow_Meter_ert_rtw\\Flow_Meter.c",
	size: 369};
	 this.metricsArray.fcn["Flow_Meter_initialize"] = {file: "C:\\Users\\Vishnu\\AppData\\Local\\Packages\\microsoft.windowscommunicationsapps_8wekyb3d8bbwe\\LocalState\\Files\\S0\\294\\Flow_Meter_ert_rtw\\Flow_Meter.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["Flow_Meter_step"] = {file: "C:\\Users\\Vishnu\\AppData\\Local\\Packages\\microsoft.windowscommunicationsapps_8wekyb3d8bbwe\\LocalState\\Files\\S0\\294\\Flow_Meter_ert_rtw\\Flow_Meter.c",
	stack: 12,
	stackTotal: 12};
	 this.metricsArray.fcn["sin"] = {file: "C:\\Program Files\\MATLAB\\R2017b\\sys\\lcc\\include\\math.h",
	stack: 0,
	stackTotal: 0};
	 this.getMetrics = function(token) { 
		 var data;
		 data = this.metricsArray.var[token];
		 if (!data) {
			 data = this.metricsArray.fcn[token];
			 if (data) data.type = "fcn";
		 } else { 
			 data.type = "var";
		 }
	 return data; }; 
	 this.codeMetricsSummary = '<a href="Flow_Meter_metrics.html">Global Memory: 385(bytes) Maximum Stack: 12(bytes)</a>';
	}
CodeMetrics.instance = new CodeMetrics();
