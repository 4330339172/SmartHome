package com.example.loginpage.tools;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.TextView;

import com.example.loginpage.R;
import com.example.loginpage.mode.listviewmode;

import java.util.List;

public class MyListViewAdapter extends ArrayAdapter<listviewmode> {

        private int resourceId;

        public MyListViewAdapter(Context context, int textViewResourceId, List<listviewmode> objects){
            super(context, textViewResourceId, objects);
            resourceId = textViewResourceId;
        }

        @Override
        public View getView(int position, View convertView, ViewGroup parent){
            listviewmode mode = getItem(position); //获取当前项的Fruit实例
            View view;
            ViewHolder viewHolder;

            if(convertView==null) {
                view=LayoutInflater.from(getContext()).inflate(resourceId,parent,false);
                viewHolder = new ViewHolder();
                viewHolder.list_item_image = (ImageView) view.findViewById(R.id.list_item_image);
                viewHolder.list_item_name = (TextView) view.findViewById(R.id.list_item_name);
                viewHolder.list_item_introduce=(TextView)view.findViewById(R.id.list_item_introduce);
                view.setTag(viewHolder); //将viewHolder存储在View中
            }
            else {
                view=convertView;
                viewHolder = (ViewHolder) view.getTag();
            }
            viewHolder.list_item_image.setImageResource(mode.getIcon());
            viewHolder.list_item_name.setText(mode.getName());
            viewHolder.list_item_introduce.setText(mode.getIntroduce());
            return view;
        }


        class ViewHolder{
        ImageView list_item_image;
        TextView list_item_name;
        TextView list_item_introduce;
        }


}

