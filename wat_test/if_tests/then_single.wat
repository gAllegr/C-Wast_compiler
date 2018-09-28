(module
  (import "console" "log" (func $log (param i32) (param i32)))
  (import "js" "mem" (memory 1))
  (data (i32.const 0) "Variable has a value of 5")
  (func (export "main") 
    (local $cond i32)

    (set_local $cond (i32.const 5))   

    (if (i32.eq (get_local $cond) (i32.const 5)) 
        (then 
            (call $log
                (i32.const 0)
                (i32.const 25)
            )
        )
    )

    (return (i32.const 0))
  )
)