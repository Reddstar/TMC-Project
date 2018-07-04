;; -*-lisp-*-
(defun Sigali ()
  (interactive)
  (switch-to-buffer "*Sigali results*")
  (make-comint "Sigali results" (concat (getenv "SIGALIROOT") "/bin/" (concat "sigali-" (system-name))) () "" "")
  )
