package com.example.smarthomeapp.tools;

import android.util.Log;
import com.example.smarthomeapp.R;
import java.lang.reflect.Field;
import java.util.HashMap;
import java.util.Map;

public class DrawableMap {
    private static DrawableMap instance;
    public static Map<String, Integer> drawableMap = new HashMap<>();

    private DrawableMap() {
        Field[] fields = R.drawable.class.getDeclaredFields();
        for (Field field : fields) {
            try {
                String name = field.getName();
                int resId = field.getInt(null);
                drawableMap.put(name, resId);
            } catch (IllegalAccessException e) {
                Log.e("DrawableUtils", "Error accessing drawable resource", e);
            }
        }
    }

    public static synchronized DrawableMap getInstance() {
        if (instance == null) {
            instance = new DrawableMap();
        }
        return instance;
    }
}