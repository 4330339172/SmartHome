package com.example.smarthomeapp.mode;

public class listviewmode {
    private  String name;    //名字
    private String introduce;   //介绍
    private  int icon;  //图片

    public listviewmode() {
    }

    public  listviewmode(String name,String introduce,int icon) {
        this.name=name;
        this.introduce=introduce;
        this.icon=icon;
    }

    public  String getName(){
        return name;
    }

    public  String getIntroduce(){
        return introduce;
    }

    public int getIcon()
    {
        return  icon;
    }


}
