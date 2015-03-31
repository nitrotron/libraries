// *** SendandReceiveBinaryArguments ***

// This example expands the previous SendandReceiveArguments example. The Arduino will 
//  receive and send multiple Binary values, demonstrating that this is more compact and faster. 
// Since the output is not human readable any more, the logging is disabled and the NewLines 
// are removed
//
// It adds a demonstration of how to:
// - Send binary parameters
// - Receive binary parameters,


#include <CmdMessenger.h>  // CmdMessenger
#include <OneWire.h>		//One Wire Library
#include <DallasTemperature.h> 

// Data Wire is plugged into port 2 on the Arduino
#DEFINE ONE_WIRE_BUS 2
#DEFINE SERIAL_BAUD 9600
#DEFINE ALARM_PIN 13
#DEFINE ALARM_RESET_BUTTON_PIN
#DEFINE NUM_OF_THERMOMETERS 2

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

DeviceAddress thermometersArray[NUM_OF_THERMOMETERS];


// Attach a new CmdMessenger object to the default Serial port
CmdMessenger cmdMessenger = CmdMessenger(Serial);

// This is the list of recognized commands. These can be commands that can either be sent or received. 
// In order to receive, attach a callback function to these events
enum
{
	ReturnUnknownCmd,
	ReturnStatus,
    GetTemps,
	GetTemp,
	ReturnTemps,
	GetSensors,
	GetSensor,
	ReturnSensors,
	SetSensorID,
	GetTempAlarms,
	ReturnTempAlarms,
	SetTempAlarmHigh,
	ReturnTempAlarmHigh,
	SetTempAlarmLow,
	ReturnTempAlarmLow,
	ClearTempAlarms,
	GetTimers,
	GetTimer,
	ReturnTimers
};

// Callbacks define on which received commands we take action
void attachCommandCallbacks()
{
  // Attach callback methods
  cmdMessenger.attach(onReturnUnknownCmd);
  cmdMessenger.attach(ReturnStatus,           onReturnStatus);
  cmdMessenger.attach(GetTemps,               onGetTemps);
  cmdMessenger.attach(GetTemp,  			  onGetTemp);
  cmdMessenger.attach(ReturnTemps,  		  onReturnTemps);
  cmdMessenger.attach(GetSensors,  			  onGetSensors);
  cmdMessenger.attach(GetSensor,  			  onGetSensor);
  cmdMessenger.attach(ReturnSensors,  		  onReturnSensors);
  cmdMessenger.attach(SetSensorID,  		  onSetSensorID);
  cmdMessenger.attach(GetTempAlarms,  		  onGetTempAlarms);
  cmdMessenger.attach(ReturnTempAlarms,  	  onReturnTempAlarms);
  cmdMessenger.attach(SetTempAlarmHigh,  	  onSetTempAlarmHigh);
  cmdMessenger.attach(ReturnTempAlarmHigh,    onReturnTempAlarmHigh);
  cmdMessenger.attach(SetTempAlarmLow,  	  onSetTempAlarmLow);
  cmdMessenger.attach(ReturnTempAlarmLow,  	  onReturnTempAlarmLow);
  cmdMessenger.attach(ClearTempAlarms,  	  onClearTempAlarms);
  cmdMessenger.attach(GetTimers,  			  onGetTimers);
  cmdMessenger.attach(GetTimer,  			  onGetTimer);
  cmdMessenger.attach(ReturnTimers, 		  onReturnTimers);
 }

// ------------------  C A L L B A C K S -----------------------
// Called when a received command has no attached function
void onReturnUnknownCmd()
{
  cmdMessenger.sendCmd(ReturnUnknownCmd,"Command without attached callback");
}

//Used to provide general status()
void onReturnStatus()
{

}

//  Called function to send back all of the temperature probes' temperature
void onGetTemps()
{
  cmdMessenger.sendCmd(ReturnUnknownCmd,"Currently unsupported callback");
}

// Called function to send back specific temperature probe's temperature
void onReturnTemps()
{
  cmdMessenger.sendCmd(ReturnUnknownCmd,"Currently unsupported callback");
}
// Called function to send back specific temperature probe's temperature
void onGetSensors()
{
  cmdMessenger.sendCmd(ReturnUnknownCmd,"Currently unsupported callback");
}
// Called function to send back specific temperature probe's temperature
void onGetSensor()
{
  cmdMessenger.sendCmd(ReturnUnknownCmd,"Currently unsupported callback");
}

// Called function to send back specific temperature probe's temperature
void onReturnSensors()
{
  cmdMessenger.sendCmd(ReturnUnknownCmd,"Currently unsupported callback");
}
// Called function to send back specific temperature probe's temperature
void onSetSensorID()
{
  cmdMessenger.sendCmd(ReturnUnknownCmd,"Currently unsupported callback");
}
// Called function to send back specific temperature probe's temperature
void onGetTempAlarms()
{
  cmdMessenger.sendCmd(ReturnUnknownCmd,"Currently unsupported callback");
}
// Called function to send back specific temperature probe's temperature
void onReturnTempAlarms()
{
  cmdMessenger.sendCmd(ReturnUnknownCmd,"Currently unsupported callback");
}
// Called function to send back specific temperature probe's temperature
void onSetTempAlarmHigh()
{
  cmdMessenger.sendCmd(ReturnUnknownCmd,"Currently unsupported callback");
}
// Called function to send back specific temperature probe's temperature
void onReturnTempAlarmHigh()
{
  cmdMessenger.sendCmd(ReturnUnknownCmd,"Currently unsupported callback");
}
// Called function to send back specific temperature probe's temperature
void onSetTempAlarmLow()
{
  cmdMessenger.sendCmd(ReturnUnknownCmd,"Currently unsupported callback");
}
// Called function to send back specific temperature probe's temperature
void onReturnTempAlarmLow()
{
  cmdMessenger.sendCmd(ReturnUnknownCmd,"Currently unsupported callback");
}
// Called function to send back specific temperature probe's temperature
void onClearTempAlarms()
{
  cmdMessenger.sendCmd(ReturnUnknownCmd,"Currently unsupported callback");
}
// Called function to send back specific temperature probe's temperature
void onGetTimers()
{
  cmdMessenger.sendCmd(ReturnUnknownCmd,"Currently unsupported callback");
}
// Called function to send back specific temperature probe's temperature
void onGetTimer()
{
  cmdMessenger.sendCmd(ReturnUnknownCmd,"Currently unsupported callback");
}
// Called function to send back specific temperature probe's temperature
void onReturnTimers()
{
  cmdMessenger.sendCmd(ReturnUnknownCmd,"Currently unsupported callback");
}


// Callback function calculates the sum of the two received float values
void OnRequestPlainTextFloatSeries()
{
  // Get series length from 1st parameter
  int seriesLength = cmdMessenger.readIntArg();
  float seriesBase = cmdMessenger.readFloatArg();
 
  // Send back series of floats
  for(int i=0;i< seriesLength;i++) {
     cmdMessenger.sendCmdStart (kReceivePlainTextFloatSeries);
     cmdMessenger.sendCmdArg<float>(((float)i*(float)seriesBase),6);
     cmdMessenger.sendCmdEnd ();
  }
}

// Callback function calculates the sum of the two received float values
void OnRequestBinaryFloatSeries()
{
  // Get series length from 1st parameter
  int seriesLength = cmdMessenger.readBinArg<uint16_t>();
  float seriesBase = cmdMessenger.readBinArg<float>(); 

  // Disable new lines, this saves another 2 chars per command
  cmdMessenger.printLfCr(false); 
  // Send back series of floats
  for(int i=0;i< seriesLength;i++) {
     cmdMessenger.sendCmdStart (kReceiveBinaryFloatSeries);
     cmdMessenger.sendCmdBinArg<float>(((float)i*(float)seriesBase));
     cmdMessenger.sendCmdEnd ();
  }
  // Re-enable new lines, for human readability
  cmdMessenger.printLfCr(true); 
}

// ------------------ M A I N  ----------------------

// Setup function
void setup() 
{
  // Listen on serial connection for messages from the pc
  Serial.begin(SERIAL_BAUD); 


  // ----------- CMD MESSENGER -----------------------
  // Adds newline to every command
  cmdMessenger.printLfCr();   

  // Attach my application's user-defined callback methods
  attachCommandCallbacks();

  // ----------- DALLAS ONE WIRE----------------------
  // start up the library 
  sensors.begin();

  //locate devices on the bus
  cmdMessenger.sendCmd(ReturnStatus,"Arduino has started!");
  cmdMessenger.sendCmdStart (ReturnStatus);
  cmdMessenger.sendCmdArg("Found");
  cmdMessenger.sendCmdArg(sensors.getDeviceCount());
  cmdMessenger.sendCmdArg("Devices");
  cmdMessenger.sendCmdEnd ();

  // search for devices on the bus and assign based on an index.
  for (int i=0; i < NUM_OF_THERMOMETERS; i++)
  {
    if (!sensors.getAddress(thermometer[0], 0)) 
	{
	  Serial.println("Unable to find address for Device 0"); 
	  continue;
	}

    // show the addresses we found on the bus
    Serial.print("Device %i Address: ",i);
    printAddress(thermometer[i]);
    Serial.println();
   
    Serial.print("Device %i Alarms: "i );
    printAlarms(insideThermometer);
    Serial.println();
    
    
    Serial.println("Setting alarm temps...");
   
    // alarm when temp is higher than 30C
    sensors.setHighAlarmTemp(thermometer[i], 30);
    
    // alarm when temp is lower than -10C
    sensors.setLowAlarmTemp(thermometer[i], -10);
    
    
    Serial.print("New Device N Alarms: ");
    printAlarms(thermometer[i]);
    Serial.println();
    
    
  } // for
  



}

// Returns if it has been more than interval (in ms) ago. Used for periodic actions
bool hasExpired(unsigned long &prevTime, unsigned long interval) {
  if (  millis() - prevTime > interval ) {
    prevTime = millis();
    return true;
  } else     
    return false;
}

// Loop function
void loop() 
{
  // Process incoming serial data, and perform callbacks
  cmdMessenger.feedinSerialData(); 
} 
