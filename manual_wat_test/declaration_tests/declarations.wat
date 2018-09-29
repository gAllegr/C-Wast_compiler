(module
  (import "console" "str_log" (func $str_log (param i32) (param i32)))
  (import "console" "log" (func $log (param i32)))
  (import "js" "mem" (memory 1))
  (data (i32.const 0) "3")
  (data (i32.const 2) "543")
  (data (i32.const 6) "100.201")
  (data (i32.const 3) "6.7")
  (data (i32.const 4) "b")
  (data (i32.const 6) "Hello")
  (global $a i32 (i32.const 0))
  (global $b i32 (i32.const 2))
  (global $c i32 (i32.const 0))
  (global $d f32 (f32.const 0))
  (func (export "main") 
    (local $e i32)
    (local $letter i32)
    (local $say i32)

    (set_local $e
      (i32.const 2)
    )
    (set_local $letter
      (i32.const 4)
    )
    (set_local $say
      (i32.const 6)
    )

    (call $log
      (get_global $b)
    )
    (call $str_log
      (get_global $c)
      (i32.const 2)
    )
    (call $str_log
      (get_local $e)
      (i32.const 2)
    )
    (call $str_log
      (get_local $letter)
      (i32.const 1)
    )
    (call $str_log
      (get_local $say)
      (i32.const 5)
    )
  )
)