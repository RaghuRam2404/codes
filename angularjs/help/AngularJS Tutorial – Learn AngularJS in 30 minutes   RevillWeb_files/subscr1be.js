$(function(){
    $('.subscr1be-btn').click(function(){
        $.ajax({
            type: "POST",
            url: ajax_var_1.ajax_url,
            data: "action=new-subscription&nonce=" + ajax_var_1.nonce + "&email=" + $('.subscribe-email').val(),
            success: function(response){
                var response = JSON.parse(response);
                if (response.success) {
                    $('.subscribe-email').removeClass("error");
                    $('.widget-error').addClass("success").text("Your email subscription has been accepted.");
                } else {
                    $('.subscribe-email').addClass("error");
                    $('.widget-error').removeClass("success").text(response.error);
                }
            }
        });
    });
});