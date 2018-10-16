(module
    (import "console" "str_log" (func $str_log (param i32) (param i32)))
    (import "console" "int_log" (func $log (param i32)))
    (import "js" "mem" (memory 1))
    (data (i32.const 0) "abc")
    (global $n (import "js" "glob_number") (mut i32))
    (global $t (import "js" "glob_text") (mut i32))
    (global $l (import "js" "text_length") (mut i32))
    (func (export "main")
    (call $log (i32.const 5))
        ;; print out number
        (call $log
            (get_global $n)
        )
    (call $log (i32.const 15))
        ;; print out string
        (call $str_log
            (get_global $t)
            (get_global $l)
        )
    (call $log (i32.const 25))
    )
)