package com.sjq.learnndk

import android.graphics.BitmapFactory
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import com.sjq.learnndk.bean.Animal
import com.sjq.learnndk.bitmap.JNIBItmap
import com.sjq.learnndk.jni.*
import com.sjq.learnndk.jni.base.ICallbackMethod
import com.sjq.learnndk.jni.base.IThreadCallback
import com.sjq.learnndk.load.JNIDynamicLoad
import com.sjq.learnndk.thread.JNIThread
import kotlinx.android.synthetic.main.activity_main.*
import java.lang.IllegalArgumentException

class MainActivity : AppCompatActivity() {

    var strings = arrayOf("apple","pear","banana")
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        // Example of a call to a native method
//        sample_text.text = stringFromJNI()

        var jniBitmap = JNIBItmap()
        var bitmap = BitmapFactory.decodeResource(resources,R.drawable.genus)
        iv_genius.setOnClickListener(){
            var result = jniBitmap.callNativeMirrorBitmap(bitmap)
            iv_genius.setImageBitmap(result)
        }
        var jLoad = JNIDynamicLoad()
        sample_text.setOnClickListener(){
            sample_text.text = jLoad.nativeString
        }
        var jniBasicType = JNIBasicType();
        tv_testnumber.setOnClickListener(){
            Log.i("----------",jniBasicType.callNativeInt(3).toString())
        }
        var jniStr = JNIString();
        tv_teststr.setOnClickListener(){
            Log.i("----------",jniStr.callNativeString("hhhhhhhhh"))
            jniStr.stringMethod("jj0000jjj")
        }
        var jniReference = JNIReferenceType();
        tv_testarray_item.setOnClickListener(){
            Log.i("-------------","array item is"+ jniReference.callNativeStringArray(strings))
        }

        var jniAccess = JNIAccessField()
        var animal = Animal("dog")
        tv_testaccess_field.setOnClickListener(){
            jniAccess.accessInstanceField(animal)
            jniAccess.accessStaticField(animal)
            JNIAccessField.staticAccessInstanceField()
            Log.i("--------","name is " + animal.name)
            Log.i("---------","num is "+ Animal.getNum())
            Log.i("----------","new num is "+ JNIAccessField.num)
        }

        var animal1 = Animal("animal")
        var jniAccessMethod = JNIAccessMethod()
        tv_c_open_java.setOnClickListener(){
            jniAccessMethod.accessStatiMethod(animal1)
            jniAccessMethod.accessInstanceMethod(animal1)
        }

        var jniInvokeMethod = JNIInvokeMethod()
        tv_native_huidiao_thread.setOnClickListener {
            jniInvokeMethod.nativeCallback(object :ICallbackMethod{
                override fun callback() {
                    Log.i("----------","thread name is " + Thread.currentThread().name)
                }

            })
            jniInvokeMethod.nativeThreadCallback(object :IThreadCallback{
                override fun callback() {
                    Log.i("----------","thread name is " + Thread.currentThread().name)
                }

            })

        }

        var jniConstrClass = JNIConstructorClass()
        tv_native_constructor.setOnClickListener {

//            Log.i("--------","name is " + jniConstrClass.allocObjectConstructor().name)
//            Log.i("---------","name is "+ jniConstrClass.invokeAnimalConstructors().name)
        }

        var jniNativeReference = JNIReference()
        tv_native_reference.setOnClickListener {
//            jniNativeReference.cacheWithGlobalReference()
//            jniNativeReference.errorCacheLocalReference()
//            jniNativeReference.useWeakGLobalReference()
        }

        var jniException = JNIException()
        tv_native_java_exception.setOnClickListener {

            try {
                jniException.nativeInvokeJavaException()

            }catch (e:IllegalArgumentException){

                Log.i("---------",e.message)
            }
//            jniException.nativeThrowException()
        }

        var jniThread = JNIThread()
        tv_no_params_thread.setOnClickListener {

            jniThread.createNativeThread()
        }
        tv_has_params_thread.setOnClickListener {

            jniThread.createNativeThreadWithArgs()
        }
        tv_join_thread.setOnClickListener {

            jniThread.joinNativeThread()
        }

        tv_thread_wait.setOnClickListener {
            jniThread.waitNativeThread()
        }

        tv_thread_notify.setOnClickListener {
            jniThread.notifyNativeThread()
        }

        tv_thread_product_consumer.setOnClickListener {
//            jniThread.startProduceAndConsumerThread()
        }

    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String

    companion object {

        // Used to load the 'native-lib' library on application startup.
        init {
            System.loadLibrary("native-lib")
        }
    }
}
