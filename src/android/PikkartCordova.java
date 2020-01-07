package pikkart.cordova.recognition.PikkartCordova;

import android.content.Intent;

import org.apache.cordova.CallbackContext;
import org.apache.cordova.CordovaPlugin;
import org.json.JSONArray;
import org.json.JSONException;
import com.pikkart.pikkart_ar_sdk_cms.CordovaRecognitionActivity;

public class PikkartCordova extends CordovaPlugin {

  public PikkartCordova() {
  }

  @Override
  public boolean execute(String action, JSONArray args, CallbackContext callbackContext) throws JSONException {

    return runPikkartRecognition();
  }

  private boolean runPikkartRecognition() {
    Intent intent = (new Intent()).setClass(cordova.getActivity(), CordovaRecognitionActivity.class);
    intent.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);


      cordova.getActivity().startActivity(intent);

    return true;
  }
}
