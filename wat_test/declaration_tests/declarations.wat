(module
  (import "console" "str_log" (func $str_log (param i32) (param i32)))
  (import "console" "log" (func $log (param i32)))
  (import "js" "mem" (memory 1))
  (global $a i32 (i32.const 0))
  (global $b i32 (i32.const 2))
  (global $d f32 (f32.const 0))
  (data (i32.const 0) "b")
  (data (i32.const 50) "Hello")
  (func (export "main") 
    (local $letter i32)
    (local $say i32)
    (local $c i32)

    (set_local $letter
      (i32.const 0)
    )
    (set_local $say
      (i32.const 50)
    )
    (set_local $c
      (i32.const 50)
    )

    (call $str_log
      (get_local $letter)
      (i32.const 1)
    )
    (call $str_log
      (get_local $say)
      (i32.const 5)
    )
    (call $log
      (get_local $c)
    )
  )
)