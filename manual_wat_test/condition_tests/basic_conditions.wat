(module
  (import "console" "log" (func $log (param i32) (param i32)))
  (import "js" "mem" (memory 1))
  (data (i32.const 0) "Variable is equal to 5")
  (data (i32.const 50) "Variable is not equal to 5")
  (data (i32.const 100) "Variable value is less than 5")
  (data (i32.const 150) "Variable value is less than or equal to 5")
  (data (i32.const 200) "Variable value is greater than 5")
  (data (i32.const 250) "Variable value is greater than or equal to 5")
  (func (export "main") (result i32)
    (local $cond i32)
    (set_local $cond (i32.const 5))

    (if (i32.eq (get_local $cond) (i32.const 5))
        (then   
            (call $log
                (i32.const 0)
                (i32.const 22)
            )
        )
    )

    ( if (i32.ne (get_local $cond) (i32.const 5))
        (then   
            (call $log
                (i32.const 50)
                (i32.const 26)
            )
        )
    )

    ( if (i32.lt_s (get_local $cond) (i32.const 5))
        (then   
            (call $log
                (i32.const 100)
                (i32.const 29)
            )
        )
    )

    ( if (i32.le_s (get_local $cond) (i32.const 5))
        (then   
            (call $log
                (i32.const 150)
                (i32.const 41)
            )
        )
    )

    ( if (i32.gt_s (get_local $cond) (i32.const 5))
        (then   
            (call $log
                (i32.const 200)
                (i32.const 32)
            )
        )
    )

    ( if (i32.ge_s (get_local $cond) (i32.const 5))
        (then   
            (call $log
                (i32.const 250)
                (i32.const 44)
            )
        )
    )

    (return (i32.const 0))
  )
)