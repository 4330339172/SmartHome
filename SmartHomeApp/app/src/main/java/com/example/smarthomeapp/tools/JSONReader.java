package com.example.smarthomeapp.tools;

import android.content.Context;
import android.content.res.AssetManager;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

import com.example.smarthomeapp.mode.listviewmode;

public class JSONReader {
    public static String readJSONFromAsset(Context context, String fileName) {
        StringBuilder jsonString = new StringBuilder();
        try {
            AssetManager assetManager = context.getAssets();
            BufferedReader reader = new BufferedReader(new InputStreamReader(assetManager.open(fileName), "UTF-8"));
            String line;
            while ((line = reader.readLine()) != null) {
                jsonString.append(line);
            }
            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return jsonString.toString();
    }

    public static List<listviewmode> parseJSON(Context context,String jsonString) {
        List<listviewmode> list = new ArrayList<>();
        try {
            JSONArray jsonArray = new JSONArray(jsonString);
            for (int i = 0; i < jsonArray.length(); i++) {
                JSONObject item = jsonArray.getJSONObject(i);
                String name = item.getString("name");
                String introduce = item.getString("introduce");
                String iconName = item.getString("icon");
                int icon = getIconResourceId(context,iconName);
                list.add(new listviewmode(name, introduce, icon));
            }
        } catch (JSONException e) {
            e.printStackTrace();
        }
        return list;
    }

    private static int getIconResourceId(Context context,String iconName) {
// 这里你需要根据你的实际情况获取资源ID
// 例如，如果你的图片资源在 drawable 文件夹中，你可以这样做：
        return context.getResources().getIdentifier(iconName, "drawable", context.getPackageName());
        //  return 0; // 这是一个占位符，你需要根据实际情况返回正确的资源ID
    }
}
