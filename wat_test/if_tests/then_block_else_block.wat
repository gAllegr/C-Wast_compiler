(module
  (import "console" "log" (func $log (param i32) (param i32)))
  (import "js" "mem" (memory 1))
  (data (i32.const 0) "Variable has a value greater then 5")
  (data (i32.const 50) "Variable has a value lesser then or equal to 5")
  (func (export "main") 
    (local $cond i32)

    (set_local $cond (i32.const 5))   

    (if (i32.gt_s (get_local $cond) (i32.const 5)) 
        (then 
            (call $log
                (i32.const 0)
                (i32.const 35)
            )
        )
        (else   
            (call $log
                (i32.const 50)
                (i32.const 46)
            )
        )
    )

    (return (i32.const 0))
  )
)