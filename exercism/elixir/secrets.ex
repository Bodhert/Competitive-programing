defmodule Secrets do
  @type fn_return :: (number -> number)

  @spec secret_add(number) :: fn_return
  def secret_add(secret) do
    fn inner_param ->
      secret + inner_param
    end
  end

  @spec secret_subtract(number) :: fn_return
  def secret_subtract(secret) do
    fn inner_param ->
      inner_param - secret
    end
  end

  @spec secret_multiply(number) :: fn_return
  def secret_multiply(secret) do
    fn inner_param ->
      inner_param * secret
    end
  end

  @spec secret_divide(number) :: fn_return
  def secret_divide(secret) do
    fn inner_param ->
      trunc(inner_param / secret)
    end
  end

  @spec secret_and(number) :: fn_return
  def secret_and(secret) do
    fn inner_param ->
      Bitwise.&&&(secret, inner_param)
    end
  end

  @spec secret_xor(number) :: fn_return
  def secret_xor(secret) do
    fn inner_param ->
      Bitwise.^^^(secret, inner_param)
    end
  end

@spec secret_combine(fn_return, fn_return) :: fn_return
  def secret_combine(secret_function1, secret_function2) do
    fn inner_param ->
      inner_param
      |> secret_function1.()
      |> secret_function2.()
    end
  end
end
