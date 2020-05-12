package com.example.myapplication;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

public class DB extends SQLiteOpenHelper {
    private static final String DATABASE_NAME="test";
    private static final String TABLE_NAME="person";
    private static final String col1="id";
    private static final String col2="name";
    private static final String col3="age";

    DB(Context context) {
        super(context, DATABASE_NAME, null, 1);
    }

    @Override
    public void onCreate(SQLiteDatabase sqLiteDatabase) {
        sqLiteDatabase.execSQL("create table "+TABLE_NAME+ " (id integer primary key, name text, age integer) ");
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {

    }
    boolean insert(int id, String name, int age){
        SQLiteDatabase db=this.getWritableDatabase();
        ContentValues contentValues=new ContentValues();
        contentValues.put(col1,id);
        contentValues.put(col2,name);
        contentValues.put(col3,age);
        long result= db.insert(TABLE_NAME,null,contentValues);
        return result != -1;
    }
    Cursor getAllData(){
        SQLiteDatabase db=this.getWritableDatabase();
        return db.rawQuery("select * from "+TABLE_NAME,null);
    }
    boolean update(String id, String nume, int varsta){
        SQLiteDatabase db=this.getWritableDatabase();
        ContentValues contentValues=new ContentValues();
        contentValues.put(col2,nume);
        contentValues.put(col3,varsta);
        long result=0;
        try{
        result= db.update(TABLE_NAME,contentValues," id=?",new String []{id});
        return result != 0;
        }
        catch (Exception ignored) {}
        return false;

    }
    void delete(int id){
        SQLiteDatabase db=this.getWritableDatabase();
        long result= db.delete(TABLE_NAME," id=?",new String []{String.valueOf(id)});
    }
}
