(module

  (import "console" "str_log" (func $str_log (param i32) (param i32)))
  (import "js" "mem" (memory 1))

  (data (i32.const 0) "Variable is equal to 5\n")
  (data (i32.const 24) "Variable is not equal to 5\n")
  (data (i32.const 52) "Variable value is less than 5\n")
  (data (i32.const 83) "Variable value is less than or equal to 5\n")
  (data (i32.const 126) "Variable value is greater than 5\n")
  (data (i32.const 160) "Variable value is greater than or equal to 5\n")

  (func (export "main") (result i32)

    (local $cond i32)
    (set_local $cond (i32.const 5))
    (if (i32.eq (get_local $cond) (i32.const 5))
      (then
        (call $str_log
          (i32.const 0)
          (i32.const 23)
        )
      )
    )
    (if (i32.ne (get_local $cond) (i32.const 5))
      (then
        (call $str_log
          (i32.const 24)
          (i32.const 27)
        )
      )
    )
    (if (i32.lt_s (get_local $cond) (i32.const 5))
      (then
        (call $str_log
          (i32.const 52)
          (i32.const 30)
        )
      )
    )
    (if (i32.le_s (get_local $cond) (i32.const 5))
      (then
        (call $str_log
          (i32.const 83)
          (i32.const 42)
        )
      )
    )
    (if (i32.gt_s (get_local $cond) (i32.const 5))
      (then
        (call $str_log
          (i32.const 126)
          (i32.const 33)
        )
      )
    )
    (if (i32.ge_s (get_local $cond) (i32.const 5))
      (then
        (call $str_log
          (i32.const 160)
          (i32.const 45)
        )
      )
    )
    (return (i32.const 0))
  )
)